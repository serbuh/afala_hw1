#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "count_sons.h"

int main(){
	if (fork()==0)
		return 0;
	
	int a = fast_count_sons(getpid());
	if (errno == EINVAL)
		printf("EINVAL\n");
	else if (errno == ESRCH)
		printf("ESRCH\n");
	else
		printf("sons:%d\n",a);

	a = fast_count_sons(1);
	if (errno == ESRCH)
		printf("ESRCH from init\n");	// Changed order
	else if (errno == EINVAL)
		printf("EINVAL from init\n");	// Changed order
	else
		printf("init sons:%d\n",a);

	// for (int i=0; i<10; i++){
	// 	printf("HELLO_%d\n",i);
	// }
	return 0;
}
