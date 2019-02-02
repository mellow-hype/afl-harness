#include <stddef.h>
#include <stdio.h>

// cleanup (free the buffer at bufptr)
void cleanup(void *bufptr);

// Error handlers
void file_read_error(FILE *fd, void *buffer);
void file_size_error(FILE *fd);
void file_open_error(FILE *fd);
void alloc_error();

// get the filename from the commandline args (expects only the filename as an arg)
char * get_filename_from_args(int argc, char **argv);

// read testcase from file and return in buffer
char * read_testcase(char *filename);
