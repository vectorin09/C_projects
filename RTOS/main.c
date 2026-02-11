#include<stdio.h>
#include<stdlib.h>
#include"timer.h"
#include"schedular.h"
#include"task.h"

int main()
{
        printf("\n=====mini rtos schedular======\n");
        schedular_init();
        timer_init();

        schedular_add_task(task_led_blink,1000);
        schedular_add_task(task_print_time,2000);
        schedular_add_task(task_sensor_read,3000);
        while(1)
        {
                schedular_run();
        }
}

