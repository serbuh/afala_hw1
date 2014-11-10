#include <stdio.h>
#include "count_sons.h"

int main(){ 
	printf("creating sons...\n");
	int res;
	res = fork();
	if(res == 0){ //father
		res = fork();
		if(res == 0) while(1);
		res = fork();
		if(res == 0) while(1);
		res = fork();	
		if(res == 0) while(1);
	//
	// here father will die
	}else{
		while(1);
	}
	return 0;
}
