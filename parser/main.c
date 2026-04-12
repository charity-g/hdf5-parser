//  preprocessor directives = anything with hash
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include "errorUtils.h"

static void read_file_per_byte(const char *path)
{
    FILE * fp = fopen(path, "rb");
    if (fp == NULL) {
        perror_debug("read_file_per_byte", "fopen failed");
        return;
    }

    int byte = fgetc(fp);
    int byteCount = 0;
    while (byte != EOF) {
        byteCount++;
        printf("%02X ", byte);
        byte = fgetc(fp);
    }

    printf("\nTotal bytes read: %d\n", byteCount);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    read_file_per_byte(argv[1]);
    return EXIT_SUCCESS;
}