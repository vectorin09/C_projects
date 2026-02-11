
typedef struct
{
	void(*task_function)(void);
	unsigned int interval;
	unsigned int last_run;
}Task;

#define max_task 5
void schedular_init(void);
void schedular_add_task(void(*task)(void),unsigned int interval);
void schedular_run(void);
