#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "library.h"

char *buffer;

void cleanup()
{
    free(buffer);
}

int file_open_error(FILE *fd)
{
    printf("Error: couldn't open file for reading. Exiting...\n");
    cleanup();
    fclose(fd);
    exit(1);
}

int file_read_error(FILE *fd)
{
    printf("Error reading file. Exiting...\n");
    cleanup();
    fclose(fd);
    exit(1);
}

int alloc_error()
{
    printf("failed to alloc memory\n");
    exit(1);
}



size_t read_testcase(FILE *testcase)
{
    size_t length;
    if (testcase != NULL)
    {
        if (fseek(testcase, 0L, SEEK_END) == 0)
        {
            /* Get the size of the file. */
            long bufsize = ftell(testcase);
            printf("filesize: %lx", bufsize);
            if (bufsize == -1) 
            {
                file_read_error(testcase);
            }

            /* Allocate our buffer to that size. */
            buffer = malloc(sizeof(char) * (bufsize + 1));
            if (buffer == NULL)
            {
                alloc_error();
            }

            /* Go back to the start of the file. */
            if (fseek(testcase, 0L, SEEK_SET) != 0) 
            {
                file_read_error(testcase); 
            }

            /* Read the entire file into memory. */
            length = fread(buffer, sizeof(char), bufsize, testcase);
            if ( ferror( testcase ) != 0 ) {
                fputs("Error reading file", stderr);
            } else {
                buffer[length++] = '\0'; /* Just to be safe. */
            }

        }
    }
    else
    {
        file_read_error(testcase);
    }
    return length;
}



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    FILE *testcase = fopen(argv[1], "r");
    size_t length = read_testcase(testcase);

    {
        // TARGET FUNCTION CALLS HERE
        target_function1(buffer, length);
    }

    fclose(testcase);
    free(buffer);
    return 0;
}