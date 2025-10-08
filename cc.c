#include<stdio.h>
#include<string.h>
struct id{
	char name[20];
	float mark;
};

struct id  sort (struct id[],int);
struct id insert(struct id[],int);
int file(struct id[],int);


int main()
{
	printf("-------------how many student record do you want to save-------  ");int y;scanf("%d",&y);
	struct id f[y];
	insert(f,y);
	file(f,y);
	printf("-----------Are you need to sort or not----------\n1.for sort\n0.No need sort\n");
	int  u;scanf("%d",&u);
	if(u)
		sort(f,y);

	
}
struct id sort(struct id var[],int n)
{
	int f;        
	printf("---How  can  i sort the details---\n1.Name\n2.marks \n" );
	scanf("%d",&f);

	if(f == 1)
        {

		for(int i=0;i<n;i++){
                	for(int j=0;j<=n-i-1;j++)
				if(strcmp(var[j].name,var[j+1].name)>0)
				{
					struct id temp=var[j];
					var[j]=var[j+1];
					var[j+1]=temp;
				}
				
		}
		

        }
	else if(f == 2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n-i-1;j++)
			{
				if(var[j].mark < var[j+1].mark)
				{
					struct id temp = var[j+1];
					var[j+1]=var[j];
					var[j]=temp;
					
				}
			}
		}
	}

	 
	return var[0];
	
}

struct id insert(struct id in[],int n)
{
	if((--n)>=0)
	{

		printf("Enter the vlues of struct [%d]",n);
		scanf("%s %f",in[n].name,&in[n].mark);
		insert(in,n);

	}
	return in[0];

	 

}
int file(struct id a[],int data_length)
{
	int option;printf("----------what do you want-------\n1.To clear the data\n2.append the data\n3.To update the student details\n");
       	scanf("%d",&option);

	if (option == 1)
	{
		FILE*file=fopen("database.txt","w");
		for(int i=0;i<data_length;i++)
		{

			fprintf(file,"%s %f\n",a[i].name,a[i].mark);
		
		}
		fclose(file);
	}
	else if(option == 2){ 
		for(int b=0;b<data_length;b++)
		{	
		FILE*file_to_append=fopen("database.txt","a+"); 
		fprintf(file_to_append,"%s %f\n",a[b].name,a[b].mark);
		fclose(file_to_append);
		}
	}


	printf("\n");
	FILE*file=fopen("database.txt","r");
	fclose(file);
}


