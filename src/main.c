#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "translator.h"

#define LINE_SIZE 65536

static void process(FILE *f) {
    char line[LINE_SIZE];
    char out[LINE_SIZE];

    while (fgets(line, sizeof(line), f)) {
        int len = (int)strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[--len] = '\0';
        if (len > 0 && line[len - 1] == '\r') line[--len] = '\0';
        translate_line(line, out, sizeof(out));
        puts(out);
    }
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    if (argc >= 2) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "jive: cannot open '%s'\n", argv[1]);
            return 1;
        }
        process(f);
        fclose(f);
    } else {
        process(stdin);
    }
    return 0;
}
