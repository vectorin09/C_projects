#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char department[8];
	char name[20];
     	int roll;
	float marks;
}ready;




ready *head_ptr;

void display();
void delete();
void insert();
void save_database();  

int main()
{
	while(1)
	{
		int  op;
		scanf("%d",&op);
		if(op == 1)
			insert();
		else if(op == 2)
			display();
		else if(op == 3)
		{
			delete();		
		}
		else
			return 0;
			
	}
}
void delete()
{
	FILE*data_base=fopen("data_base.txt","r");
	FILE*data_base_c=fopen("data_base_c.txt","w");

	int word_existance=0;
	char word[100];
	char buffer[100];
	printf("Enter the name to delete");
	scanf("%s",word);
	int count=0;
	int flag=1;
	int flag_2=0;
	while(fscanf(data_base,"%s",buffer)!=EOF)
	{
		
		if(strcmp(buffer,word)!=0 && flag)
		{
			fprintf(data_base_c,"%s",buffer);
			fprintf(data_base_c,"%c",' ');

			
		}

		else
		{
			fprintf(data_base_c,"%c",'#');
			flag=0;
			flag_2++;
			if(flag_2 == 3) flag=1;
		}
	
		
		count++;
		
		if(count == 4) 
		{
	
			fprintf(data_base_c,"%c",'\n');
			count=0;
		}
	
		
	}	
 
	fclose(data_base);
	fclose(data_base_c);	
		

}
void display()
{

	
	int count=0;
	char buffer;
	FILE*file=fopen("data_base_c.txt","r");
	while((buffer=fgetc(file))!=EOF)
	{
	
		if(buffer !='#')
		{
			printf("%c",buffer);
		}
	}


}
void insert()
{
	int op;

	char buffer;

	int count=1;
	FILE*fp=fopen("data_base.txt","r");
	if(fp != NULL)
	{
		while(((buffer=getc(fp))!=EOF))
		{	
			if(buffer == '\n')
			{
				count++;
			}

		}
	}

	printf("1.ECE\n2.MECH\n3.CIVIL\n4.EEE\nEnter the student department: ");


	scanf("%d",&op);

	
	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=count;

	if (op ==1)strcpy(temp->department,"ECE");
	else if (op ==2)strcpy(temp->department,"MECH");
	else if (op ==3)strcpy(temp->department,"CIVIL");
	else if (op ==4)strcpy(temp->department,"EEE");
	else 
		return;		

	printf("Enter the name of the student: ");
	
	scanf("%s",temp->name);

	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	save_database(temp);

		
}

void save_database(ready*details)
{
	char buffer;
	int flag=1;
	int flag_2=1;
	FILE *fl=fopen("data_base_c.txt","r+");
	while((buffer=fgetc(fl))!=EOF)
	{
		if(buffer =='#' )
		{
			long pos;
			pos=ftell(fl)-1;
			fseek(fl,pos,SEEK_SET);
			if(flag ==1 )
			{
				fprintf(fl,"%s ",details->name);
				flag++;

			}
			else if(flag ==2)
			{
				fprintf(fl,"%s ",details->department);
				flag++;
			}
			else if(flag ==3)
			{
				fprintf(fl,"%f \n",details->marks);
				flag=1;
			}
			
			flag_2=0;
		}
	}
	fclose(fl);
	
	if(flag_2)
	{
		FILE*file=fopen("data_base.txt","a");
	
		fprintf(file,"%d  ",details->roll);
		fprintf(file,"%s  ",details->name);
		fprintf(file,"%s ",details->department);
		fprintf(file,"%f  \n",details->marks);
		fclose(file);
	}

		
}
