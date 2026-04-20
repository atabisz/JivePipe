#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "dictionary.h"
#include "translator.h"

#define BUF 65536

static int is_word_char(char c) {
    return isalnum((unsigned char)c) || c == '_';
}

static int icmp(const char *a, const char *b, int n) {
    for (int i = 0; i < n; i++) {
        int d = tolower((unsigned char)a[i]) - tolower((unsigned char)b[i]);
        if (d) return d;
        if (!a[i]) return 0;
    }
    return 0;
}

static void apply_case(const char *orig, int orig_len,
                        const char *rep, char *out, int out_size) {
    int letters = 0, all_up = 1;
    for (int i = 0; i < orig_len; i++) {
        if (isalpha((unsigned char)orig[i])) {
            letters++;
            if (!isupper((unsigned char)orig[i])) all_up = 0;
        }
    }

    int rlen = (int)strlen(rep);
    if (rlen >= out_size) rlen = out_size - 1;

    if (letters >= 2 && all_up) {
        for (int i = 0; i < rlen; i++)
            out[i] = (char)toupper((unsigned char)rep[i]);
        out[rlen] = '\0';
    } else {
        memcpy(out, rep, (size_t)rlen);
        out[rlen] = '\0';
        if (orig_len > 0 && isupper((unsigned char)orig[0]))
            out[0] = (char)toupper((unsigned char)rep[0]);
    }
}

static int is_ing_exception(const char *word, int len) {
    for (int i = 0; i < ing_exceptions_count; i++) {
        int elen = (int)strlen(ing_exceptions[i]);
        if (elen == len && icmp(word, ing_exceptions[i], len) == 0)
            return 1;
    }
    return 0;
}

/*
 * Try matching dict entries at input[i]. On match, emits replacement into
 * buf and returns the new input position. Returns -1 on no match.
 */
static int try_match(const Entry *dict, int count,
                     const char *input, int i, int in_len,
                     char *buf, int *bufp) {
    for (int d = 0; d < count; d++) {
        int flen = (int)strlen(dict[d].from);
        if (i + flen > in_len) continue;
        if (icmp(input + i, dict[d].from, flen) != 0) continue;
        int end = i + flen;
        if (end < in_len && is_word_char(input[end])) continue;

        char rep[512];
        apply_case(input + i, flen, dict[d].to, rep, sizeof(rep));
        int rlen = (int)strlen(rep);
        if (*bufp + rlen < BUF - 1) { memcpy(buf + *bufp, rep, (size_t)rlen); *bufp += rlen; }
        return end;
    }
    return -1;
}

void translate_line(const char *input, char *output, int output_size) {
    int in_len = (int)strlen(input);

    /* Phase 1+2: single-pass phrase and word substitution (no cascade) */
    char t1[BUF];
    int t1p = 0, i = 0;

    while (i < in_len && t1p < BUF - 1) {
        int at_wb = (i == 0) || !is_word_char(input[i - 1]);
        int new_pos = -1;

        if (at_wb && is_word_char(input[i])) {
            if ((new_pos = try_match(phrases, phrases_count, input, i, in_len, t1, &t1p)) >= 0 ||
                (new_pos = try_match(words,   words_count,   input, i, in_len, t1, &t1p)) >= 0)
                i = new_pos;
        }

        if (new_pos < 0) t1[t1p++] = input[i++];
    }
    t1[t1p] = '\0';

    /* Phase 3: drop 'g' from verbal -ing endings */
    char t2[BUF];
    int t2p = 0, j = 0;

    while (j < t1p && t2p < BUF - 1) {
        int at_wb = (j == 0) || !is_word_char(t1[j - 1]);

        if (at_wb && is_word_char(t1[j])) {
            int ws = j;
            while (j < t1p && is_word_char(t1[j])) j++;
            int wlen = j - ws;

            if (wlen >= 4        /* covers "ring", "king", "sing", etc. */
                && tolower((unsigned char)t1[ws + wlen - 3]) == 'i'
                && tolower((unsigned char)t1[ws + wlen - 2]) == 'n'
                && tolower((unsigned char)t1[ws + wlen - 1]) == 'g'
                && !is_ing_exception(t1 + ws, wlen)) {

                int stem_len = wlen - 3;
                char stem_plus[512];
                if (stem_len + 3 < (int)sizeof(stem_plus)) {
                    memcpy(stem_plus, t1 + ws, (size_t)stem_len);
                    stem_plus[stem_len]     = 'i';
                    stem_plus[stem_len + 1] = 'n';
                    stem_plus[stem_len + 2] = '\'';
                    stem_plus[stem_len + 3] = '\0';

                    char rep[512];
                    apply_case(t1 + ws, wlen, stem_plus, rep, sizeof(rep));
                    int rlen = (int)strlen(rep);
                    if (t2p + rlen < BUF - 1) { memcpy(t2 + t2p, rep, (size_t)rlen); t2p += rlen; }
                    continue;
                }
            }

            if (t2p + wlen < BUF - 1) { memcpy(t2 + t2p, t1 + ws, (size_t)wlen); t2p += wlen; }
        } else {
            t2[t2p++] = t1[j++];
        }
    }
    t2[t2p] = '\0';

    /* Phase 4: filler injection (~20% on non-trivial lines) */
    int trimlen = 0;
    for (int k = 0; k < t2p; k++)
        if (!isspace((unsigned char)t2[k])) trimlen++;

    if (trimlen > 10 && (rand() % 5) == 0) {
        int end = t2p - 1;
        while (end >= 0 && (t2[end] == '.' || t2[end] == '!' || t2[end] == '?' || t2[end] == ',' || t2[end] == ';'))
            end--;
        t2p = end + 1;
        t2[t2p] = '\0';

        const char *filler = fillers[rand() % fillers_count];
        int flen = (int)strlen(filler);
        if (t2p + flen < BUF - 1) {
            int letters = 0, all_up = 1;
            for (int k = 0; k < t2p; k++) {
                if (isalpha((unsigned char)t2[k])) {
                    letters++;
                    if (!isupper((unsigned char)t2[k])) all_up = 0;
                }
            }
            if (letters >= 2 && all_up) {
                for (int k = 0; k < flen; k++)
                    t2[t2p + k] = (char)toupper((unsigned char)filler[k]);
            } else {
                memcpy(t2 + t2p, filler, (size_t)flen);
            }
            t2p += flen;
            t2[t2p] = '\0';
        }
    }

    int copy = t2p < output_size - 1 ? t2p : output_size - 1;
    memcpy(output, t2, (size_t)copy);
    output[copy] = '\0';
}
