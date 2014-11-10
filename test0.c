#include <stdio.h>
#include "count_sons.h"

int main(){
	printf("creating sons...\n");
	int res;
	res = fork();
	if(res == 0){
		sleep(3);
	}else{
	
		res = fork();
		if(res == 0){
			sleep(6);
		}else{
			res = fork();
			if(res == 0){
				sleep(9);
			}else{
				int status;
				while(wait(&status) != -1){ sleep(10); }
			}
		}
	}
		
	return 0;
}
