#ifndef __COUNT_SONS_H
#define __COUNT_SONS_H

	#include <errno.h>
	#include <sched.h>

	int slow_count_sons (int pid)
	{
		int res;
		__asm__ 
		(
	 		"int $0x80;"
	 		: "=a" (res) 
	 		: "0" (243) ,"b" (pid)
	 		: "memory"
		);
		if(res == -EINVAL){
			errno = EINVAL;
			return -1;
		}
		if(res == -ESRCH){
			errno = ESRCH;
			return -1;
		}
		return (int) res;
	}

	int fast_count_sons (int pid)
	{
		int res;
		__asm__ 
		(
	 		"int $0x80;"
	 		: "=a" (res) 
	 		: "0" (244) ,"b" (pid)
	 		: "memory"
		);
		if(res == -EINVAL){
			errno = EINVAL;
			return -1;
		}
		if(res == -ESRCH){
			errno = ESRCH;
			return -1;
		}
		return (int) res;
	}

#endif
