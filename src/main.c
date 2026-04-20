#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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

static void print_help(void) {
    puts("Usage: jive [OPTION] [FILE]");
    puts("       command | jive");
    puts("");
    puts("Translate text into jive dialect.");
    puts("Reads from FILE if given, otherwise from standard input.");
    puts("");
    puts("Options:");
    puts("  -h, --help    Show this help and exit");
    puts("");
    puts("Examples:");
    puts("  echo \"What are you doing?\" | jive");
    puts("  jive readme.txt");
    puts("  jive < input.txt > output.txt");
    puts("  git log --oneline | jive");
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL) ^ ((unsigned int)getpid() << 16));
    if (argc >= 2) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            print_help();
            return 0;
        }
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
