#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

#include<stdio.h>
#include<cstdlib>
#include<iomanip>

#include"class.h"
using namespace std;


int main()
{
	
	if((fork()==0))
	{
			


		


			FILE*fp = fopen("database_book.txt", "r");
			if(fp == NULL)
			{
				cout<<"file not found sorry!"<<endl;
				exit(0);
			}									

			int book_id;
			char book_name[20];
			int  book_count;

			while(fscanf(fp, "%d %s %d", &book_id,book_name, &book_count) == 3)
			{
				st *temp = (st*)malloc(sizeof(st));
				temp->book_id= book_id;
				temp->book_name=book_name;
				temp->book_count =book_count;
				cl.add_books(&head_ptr,temp);
			}

			fclose(fp);
			



			FILE*fp1=fopen("database_issue.txt","r");
			if(fp == NULL)
				return 0;
			
        	
        	        char*user_name;
 			int user_id;
        	  	int issue_date;
        		int due_date;
			while(fscanf(fp,"%d %d %s %s %d %d ",&book_id,&user_id,user_name,book_name,&issue_date,&due_date )==6)
			{
				user*temp=(user*)malloc(sizeof(user));
				temp->book_id=book_id;
				temp->user_id=user_id;
				temp->user_name=user_name;
				temp->book_name=book_name;
				temp->issue_date=issue_date;
				temp->due_date=due_date;
				cl.add_issue(&user_head_ptr,temp);
			}
			fclose(fp1);
	   									

		exit(0);

	}
	else
	{
		
		while(1)
		{
			interface.main_ui();
		}

	}
	


}
			
