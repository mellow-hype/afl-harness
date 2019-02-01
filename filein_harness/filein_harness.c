#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void cleanup(void *bufptr)
{
    free(bufptr);
}

// ERROR HANDLERS
void file_open_error(FILE *fd)
{
    printf("Error: couldn't open file for reading. Exiting...\n");
    fclose(fd);
    exit(1);
}

void file_size_error(FILE *fd)
{
    printf("Error: couldn't get file size. Exiting...\n");
    fclose(fd);
    exit(1);
}

void file_read_error(FILE *fd, void *buffer)
{
    printf("Error reading file. Exiting...\n");
    cleanup(buffer);
    fclose(fd);
    exit(1);
}

void alloc_error()
{
    printf("failed to alloc memory\n");
    exit(1);
}


char * read_testcase(char *filename)
{
    char* buffer;
    size_t length;
    FILE *testcase = fopen(filename, "r");
    if (testcase != NULL)
    {
        if (fseek(testcase, 0L, SEEK_END) == 0)
        {
            /* Get the size of the file. */
            long bufsize = ftell(testcase);
            printf("filesize: %ld\n", bufsize);
            if (bufsize == -1) 
            {
                file_size_error(testcase);
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
                file_read_error(testcase, buffer); 
            }

            /* Read the entire file into memory. */
            length = fread(buffer, sizeof(char), bufsize, testcase);
            if ( ferror( testcase ) != 0 ) {
                file_read_error(testcase, buffer);
            } else {
                buffer[length++] = '\0'; /* Just to be safe. */
            }

        }
    }
    else
    {
        file_open_error(testcase);
    }
    fclose(testcase);
    return buffer;
}


char * get_filename_from_args(int argc, char **argv) 
{
    if (argc != 2)
    {
        printf("usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    return argv[1];
}

