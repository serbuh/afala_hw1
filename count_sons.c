#include <../include/linux/errno.h>
#include <../include/linux/sched.h>
#include <../include/linux/kernel.h>

int sys_slow_count_sons(int pid)
{
	if (pid < 0)
		return -EINVAL;
	if (pid == 0)
		return 1;
	struct task_struct *pd = find_task_by_pid(pid);
	if(pd->state == TASK_ZOMBIE)
		return 0;
	if(pd == NULL)
		return -ESRCH;
	int sonCounter = 0;
	struct task_struct *child = pd->p_cptr;
	while (child != NULL){
		sonCounter++;
		child = child->p_osptr;
	}
	return sonCounter;
}

int sys_fast_count_sons(int pid)
{
	if (pid < 0)
		return -EINVAL;
	if (pid == 0)
		return 1;
	struct task_struct *pd = find_task_by_pid(pid);
	//printk("### sys_fast_count_sons ");
	//printk("### pid: %d ### p_opptr: %d ### p_pptr: %d ### numberOfSons: %d ###\n", pd->pid, pd->p_opptr->pid, pd->p_pptr->pid, pd->numberOfSons);
	if(pd == NULL)
		return -ESRCH;
	return pd->numberOfSons;
}
