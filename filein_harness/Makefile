
filein_example: filein_harness.o filein_example.c
	afl-gcc -w -o filein_example filein_harness.o filein_example.c 

filein_harness.o: filein_harness.c 
	afl-gcc -c filein_harness.c -o filein_harness.o

