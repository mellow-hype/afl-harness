#include <stddef.h>
#include <stdio.h>
char * buffer;

size_t read_testcase(FILE *testcase);
void file_read_error(FILE *fd);
void file_open_error(FILE *fd);
void alloc_error();

