#include <stdio.h>
#include "count_sons.h"

int main(){
	printf("creating sons...\n");
	int res;
	res = fork();
	if(res == 0){ //son1
		res = fork();
		if(res == 0){ //son21
			while(1);
		}else{
			res = fork();
			if(res == 0){ //son22
				while(1);
			}else{
				res = fork();
				if(res == 0){ //son23
					while(1);
				}else{
					//////
				}
			}
		}		
	}else{	//father
		while(1);
	}
		
	return 0;
}
