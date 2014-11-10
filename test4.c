#include <stdio.h>
//#include <errno.h>
#include "count_sons.h"

int main(int argc, char* argv[]){

	int pid = atoi(argv[1]);
	int timer = 0;

	int sons_fast = fast_count_sons(pid);
	char* err_fast = (char*)strerror(errno);
	int sons_slow = slow_count_sons(pid);
	char* err_slow = (char*)strerror(errno);

	printf("FAST: %d has: %d sons [err: %s]\n",pid, sons_fast, err_fast);
	printf("SLOW: %d has: %d sons [err: %s]\n", pid, sons_slow, err_slow);
	
	return 0;
}
