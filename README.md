# afl harnesses

a minimal library to help in the creation of test harnesses used for fuzzing independent functions/components with afl. 

## usage

build the harness library (produces `filein_harness.o`):

```
cd filein_harness
make
```

build the target library/functions:
```
afl-gcc -c target_lib.c -o target_lib.o
```

create the harness (example):

```
#include <stdio.h>
#include <string.h>
#include "filein_harness.h"
#include "target_lib.h"

int main(int argc, char **argv)
{
    // use get_filename_from_args to parse the filename from args
    char *filename = get_filename_from_args(argc, argv);

    // read the file into a char buffer with read_testcase()
    char *buffer = read_testcase(filename);

    {
        // TARGET FUNCTION CALLS + INIT HERE //
	target_function(buffer);
    }

    // use cleanup() to free the buffer that was allocated
    cleanup(buffer);
    return 0;
}
```

build the harness program:

```
afl-gcc harness.c filein_harness.o target_lib.o -o harness
```


