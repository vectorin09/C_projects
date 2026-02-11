#include<stdio.h>
#include<stdlib.h>
#include"timer.h"
#include"task.h"

void task_led_blink(void)
{
	static int ledstatus;
	ledstatus=!ledstatus;
	printf("LED is %s\n ",ledstatus ? "ON": "OFF");

}
void task_print_time(void)
{
	unsigned int task_time=milli();
	printf("system time is %u\n",task_time);

}
void task_sensor_read(void)
{
	int sensor_read=(rand() % 40);
	printf("temp:%d *C\n",sensor_read);
}


