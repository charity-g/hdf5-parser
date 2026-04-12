//  preprocessor directives = anything with hash
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
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

static void read_entire_hdf5_file_bytes(const char *path)
{
    FILE *fp = fopen(path, "rb");
    //
}

static void read_file_utf8(const char *path)
{

    //TODO
}

static void read_file_ascii(const char *path)
{

    //TODO
}

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

static void test_char_vs_btye() {
    char c[128] = "Hello, world!";  // Multibyte string
    printf("String: %s\n", c);
    
    char *s = "\u20AC1.23";

    printf("%s\n", s);  // €1.23
    for (int j = 0; j < strlen(s); j++) {
        printf("Byte %d: %02X, ", j, (unsigned char)s[j]);
    }
    printf("\n");
    printf("%zu\n", strlen(s));  // 7!

    printf("%x\n", '€');
    printf("%x\n", '\u20ac');
}

static void test_pre_post_increment()
{
    int k = 0;
    int i = 5;
    printf("k: %d\n", k + i++);
    k = 0;
    i = 5;
    printf("k: %d\n", k + ++i);
}


static int test_file_fread()
{
    const char *filename = "test1.txt";
    FILE * fp1 = fopen(filename, "r");
    if (fp1 != NULL) {
        if (remove(filename) != 0) {
            perror("Error: Unable to delete the file.\n");
            return 1;
        }
    }
    fclose(fp1);


    fp1 = fopen(filename, "w+");
    fprintf(fp1, "12345678");
    
    //EOF line reached
        // size = 1, count = 9 text file length = 8, buffer = 10 
        // size = 5; count = 2, text file length = 8, buffer = 10 
    fseek(fp1, 0, SEEK_SET);
    char buffer[11];
    fread(buffer, sizeof(char), 9, fp1);
    // expect buffer to be "12345678"
    buffer[10] = '\0'; 
    printf("Buffer: %s\n", buffer);

    fseek(fp1, 0, SEEK_SET);
    char buffer1[11];
    fread(buffer1, 5, 2, fp1);
    // expect buffer to be "12345678"
    buffer1[10] = '\0';
    printf("Buffer: %s\n", buffer1);

    // working exact
        // size = 1, count = 8 text file length = 8, buffer = 10 
        // size = 4; count = 2, text file length = 8, buffer = 10 

    fseek(fp1, 0, SEEK_SET);
    char buffer2[10];
    fread(buffer2, 1, 8, fp1);
    // expect buffer to be "12345678"
    buffer2[8] = '\0';
    printf("Buffer: %s\n", buffer2);

    fseek(fp1, 0, SEEK_SET);
    char buffer3[10];
    fread(buffer3, 4, 2, fp1);
    // expect buffer to be "12345678"
    buffer3[8] = '\0';
    printf("Buffer: %s\n", buffer3);

    // buffer overflow - UNSAFE!!!
    // size = 1, count = 8 text file length = 8, buffer = 6
    // size = 4; count = 2, text file length = 8, buffer = 6   

    fseek(fp1, 0, SEEK_SET);
    char buffer4[6];
    fread(buffer4, 1, 8, fp1);
    // expect buffer to be "12345678"
    // buffer4[8] = '\0';
    printf("Buffer: %s\n", buffer4);


    fseek(fp1, 0, SEEK_SET);
    char buffer5[6];
    fread(buffer5, 4, 2, fp1);
    // expect buffer to be "12345678"
    // buffer5[6] = '\0';
    printf("Buffer: %s\n", buffer5);
    return 0;
}

static void read_file_fread(const char *path)
{
    FILE * fp = safe_fopen(path);
    char buffer[64];

    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, fp);
    if (bytesRead < 0) {
        perror_debug("read_file_fread", "fread failed");
        fclose(fp);
        return; 
    }

    buffer[bytesRead] = '\0'; // Null-terminate the buffer
    printf("Buffer: %s\n", buffer);
    printf("Bytes read: %zu\n", bytesRead);
}


static void read_file_fscanf_s(const char *path)
{   
    FILE * fp = safe_fopen(path);
    char buffer[64];
    int number;

    int i = fscanf_s(fp, "%s %d", buffer, sizeof(buffer), &number);
    printf("matched items: %i\n", i);
    if (i == 2) {
        printf("Buffer: %s, Number: %d\n", buffer, number);
    } else {
        printf("Failed to read both string and number. Items matched: %i\n", i);
    }

    fclose(fp);

}


static void read_file_fscanf(const char *path)
{   
    FILE * fp = safe_fopen(path);
    char buffer[64];
    int number;

    int i = fscanf(fp, "%s %d", buffer, &number);
    printf("matched items: %i\n", i);
    if (i == 2) {
        printf("Buffer: %s, Number: %d\n", buffer, number);
    } else {
        printf("Failed to read both string and number. Items matched: %i\n", i);
    }

    fclose(fp);
}


static void read_file_fgetc(const char *path)
{
    FILE * fp = safe_fopen(path);
    
    int res = fgetc(fp);
    while (res > 0) {
        printf("%i-", res);
        printf("%c \n", res);
        res = fgetc(fp);
    }
    fclose(fp);
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
    // read_file_fscanf(argv[1]);
    // read_file_fscanf_s(argv[1]);
    // read_file_fread(argv[1]);
    // test_file_fread();

    // test_pre_post_increment();
    // test_char_vs_btye();
    read_file_per_byte(argv[1]);
    return EXIT_SUCCESS;
}