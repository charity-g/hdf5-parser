#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

static void perror_debug(const char *msg)
{
    char buffer[256] = {0};
    // Prevents overflow, and adds string null termination- how? TODO
    snprintf(buffer, sizeof(buffer), "[main.c read_file_byte_by_byte] %s", msg); 
    perror(buffer);
}

static void read_file_byte_by_byte(const char *path)
{
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        perror_debug("fopen failed");
        return;
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_file_byte_by_byte(argv[1]);
    return EXIT_SUCCESS;
}