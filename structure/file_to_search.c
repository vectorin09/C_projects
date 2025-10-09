#include<stdio.h>
int main()
{
        char cha;
        FILE*file_to_search=fopen("database.txt","r");
        for(int i=0;(cha=fgetc(file_to_search))!=EOF;i++)
	{
	
		if(cha=='r')printf("yeah");
	}
	                
}

