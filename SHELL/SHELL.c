#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char  home[60]={"MY SHELL >"};
	char  input[1024];// this array is used to store the char which we enter ed in the shell 
	while(1)
	{
		printf("\n");
		printf("%s",home);
		fflush(stdout);//make an stdout buffer clean or imediate print

		//this will get the user input to store an string on input array
		if(fgets(input,1024,stdin)==NULL)
		{
			break;

		}
		//gets( 3 ) function which added the new line(/n)on the last of the char, so to ignore that here we used strcspn( 3 )remove it an optional in will not make any changes on output . 
		input[strcspn(input,"\n")]=0;
		if(strcmp(input,"Exit")==0)
		{
			break;
		}
		if(strncmp(input,"cd",2)==0)
		{

			chdir(input+4);//it is an system call which is used to move back and forth towards the directories 
		        printf("%s",input+3);
			strcat(home,"/hello>");
			
			
		}
		/*if((execlp(input,input,NULL))==-1)
		{
			printf("command not found!");
			perror("wrong cmd");
		}*/
		system(input);//system( 2 ) function will give the control back to called function so it will make an continous execution without any termination of process
	//	printf("\n");
	//	printf("you entered: %s\n",input);//printout the result

	}
	return 0;
}
