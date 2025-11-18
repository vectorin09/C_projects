#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef  HEADER_H
#define HEADER_H

typedef struct student 
{
	char name[20];
	int roll;
	float marks;
	struct student *next;
}ready;
extern ready *head_ptr ;

extern int count;
extern int delete_flag;
extern int save_flag;
extern int display_file_flag;



void display(ready*);
void delete_record(ready *);
void insert(ready **);  
void mod(ready *);
void save(ready*);
void sort(ready *);
int fun_exit(void);
void display_from_file(void);
void load_from_file(void);
void reverse_print(ready *head_ptr);

#endif
