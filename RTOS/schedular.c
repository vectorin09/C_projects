#include<stdio.h>
#include"timer.h"
#include"schedular.h"
Task task[max_task];
static int task_count=0;
void schedular_arrange(void);

void schedular_init(void)
{
	task_count=0;
}
void schedular_add_task(void(*task_argument)(void),unsigned int interval)
{
	if(task_count<max_task)
	{
		task[task_count].task_function=task_argument;
		task[task_count].interval=interval;
		task[task_count].last_run=0;
		task_count++;
	}
	

}
void schedular_arrange(void)
{
	for(int i=0;i<task_count;i++)
	{
		for(int j=0;j<task_count-i-1;j++)
		{
			if(task[j].last_run > task[j+1].last_run)
			{
				 Task temp= task[j];
				task[j]=task[j+1];
				task[j+1]=temp;
			}
		}
	}
}

void schedular_run(void)
{
	 unsigned int current_time=milli();
	for(int i=0;i<task_count;i++)
	{
		if((current_time - task[i].last_run)>=task[i].interval)
		{
			task[i].task_function();
			task[i].last_run=current_time;
		}
	}
}
