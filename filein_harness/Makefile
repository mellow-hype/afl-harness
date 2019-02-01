
example: filein_harness.c filein_harness.h main.c
	afl-gcc -w filein_harness.c filein_harness.h main.c -o filein_harness

lib: filein_harness.c filein_harness.h
	afl-gcc -shared -fPIC -w filein_harness.c filein_harness.h -o filein_harness.so
