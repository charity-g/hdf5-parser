#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h> // Include errno for error handling

static void perror_debug(const char * function, const char *msg)
{
    char buffer[256] = {0};
    snprintf(buffer, sizeof(buffer), "[%s] %s", function, msg);

    if (errno == 0) {
        errno = EINVAL; // Set a default error code if errno is not set
    }

    perror(buffer);
}

static FILE * safe_fopen(const char * path) 
{
    FILE * fp = fopen(path, "r");
    if (fp == NULL) {
        perror_debug("read_file_fgets", "fopen failed");
        return NULL;
        // exit instead whatever
    }
    return fp;
}

// =================================

static void read_file_utf8(const char *path)
{

    //TODO
}

static void read_file_ascii(const char *path)
{

    //TODO
}

static void read_file_per_hex(const char *path)
{

    //TODO
}

static void read_file_byte_by_byte(const char *path)
{
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        perror_debug("read_file_byte_by_byte", "fopen failed");
        return;
    }

// TODO


    fclose(fp);
}


static void read_file_fread(const char *path)
{

    //TODO
}



static void read_file_fscans(const char *path)
{

    //TODO
}


static void read_file_fgetc(const char *path)
{
    FILE * fp = safe_fopen(path);
    char buffer[64];
    
    int res = fgetc(fp);
    while (res > 0) {
        printf("%i-", res);
        printf("%c \n", res);
        res = fgetc(fp);
    }
}

static void read_file_fgets(const char *path)
{
    FILE *fp = safe_fopen(path);
    char buffer[64];

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Buffer %i: ", i);
        printf("%s", buffer);
        i++;
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // read_file_fgets(argv[1]);
    // read_file_fgetc(argv[1]);
    // read_file_byte_by_byte(argv[1]);
    return EXIT_SUCCESS;
}