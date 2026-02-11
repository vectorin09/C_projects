#include<stdio.h>
#include"timer.h"
#include<time.h>
static clock_t start_timer;
void timer_init(void)
{
	start_timer=clock();
}
unsigned int  milli(void)
{
	clock_t now=clock();
	return (unsigned int)((now-start_timer)*1000/CLOCKS_PER_SEC);
}
void delay_ms(unsigned int ms)
{
	unsigned int start=milli();
	while((milli()-start)<ms);

}
