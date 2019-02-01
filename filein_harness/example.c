#include <stdio.h>
#include <string.h>
#include "filein_harness.h"

int main(int argc, char **argv)
{
    char *filename = get_filename_from_args(argc, argv);
    char *buffer = read_testcase(filename);

    {
        // TARGET FUNCTION CALLS HERE //
    }

    cleanup(buffer);
    return 0;
}
