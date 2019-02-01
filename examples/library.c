#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void target_function1(char *data, size_t len){
	if(strlen(data) == 0) {
        printf("bad length?\n");
		return;
	}
	char *buf = calloc(1, len);
	strncpy(buf, data, len);
	printf(buf);
	free(buf);
}

int target_function2(int x, int y){
	if(x%2 == 0) {
		return y << x;
	} else if (y%2 == 0) {
		return x << y;
	} else if (x == 0) {
		return 0;
	} else if (y == 0) {
		return 0;
	} else {
		return x * y;
	}
}