#include <stdio.h>
#include "count_sons.h"

int main(){
	printf("creating sons...\n");
	int res;
	res = fork();
	if(res == 0){
		res = fork();
		if(res == 0) while(1);
		res = fork();
		if(res == 0) while(1);
		res = fork();
		if(res == 0) while(1);
	while(1);
	}else{
		res = fork();
		if(res == 0){
			res = fork();
			if(res == 0) while(1);
			res = fork();
			if(res == 0) while(1);
		while(1);
		}else{
			while(1);
		}
	}
	return 0;
}
