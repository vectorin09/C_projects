#include<iostream>
using namespace std;

void amstrong_number(int number)
{

      	cout << "Welcome to Armstrong number checker!" << endl;

 
      	int original_number = number;
      	int sum = 0;
      	int n = 0;

    
      	while(original_number != 0) {
         	 original_number /= 10;
         	 n++;
      	}

      	original_number = number;

    
    	while(original_number != 0) {
        	int temp = original_number % 10;
        	int fact = 1;
        	for(int i = 0; i < n; i++) {
        	    fact *= temp;
        	}
        	sum += fact;
        	original_number /= 10;
    	}

    	if(sum == number) {
        	cout << number << " is an Armstrong number!" << endl;
    	} else {
        	cout << number << " is NOT an Armstrong number." << endl;
    	}

    return ;



}
void powerof2(int number)
{
	if((number&(number-1))==0)
	{
		cout<<"yeah it an powerof2"<<endl;
	}
	else 
		cout<<"no its not an powerof2"<<endl;
}
void prime_number(int number)
{
	cout<<"welcom to primenumber\n"<<endl;
	for(int i=1;i<=number;i++)
	{
		if(number%i == 0)
		{
			cout<<number<<"[number]this not an prime number"<<endl;
			return ;
		}
	}
	cout<<number<<"the number is prime number"<<endl;

	return ;

}
void strong_number(int number)
{
	cout<<"welcom to strong number checker \n"<<endl;
	int sum;int original_number;int n;
	original_number=number;
	cout<<"\n"<<endl;
	

	original_number=number;
	while(original_number!=0)
	{
		int temp=original_number % 10;
		int fab=0;
		for(int i=1;i<temp;i++)
		{
			fab+=i;

		}
		sum+=fab;
		temp/=10;

	}
	return;
}
void perfect_number(int number)
{
	int original_number;
	int sum=0;
	original_number=number;
	for(int i=1;i<=(number/2);i++)
	{
		if((number%i)==0)
		{
			sum+=i;

		}
	}	
	
	if(sum == number)
	{
		cout<<"yes this number is perfect number"<<endl;
	}
	else
		cout<<"Not an perfect number"<<endl;
}
int main()
{
	while(1)
	{
		int inputer;
		cout<<"		 press corresponding number  to check the number"<<endl;
		cout<<"		 press 1 for checking for perfect number"<<endl;
		cout<<"		 press 2 for checking for amstrong number"<<endl;
		cout<<"		 press 3 for checking for prime number "<<endl;
		cout<<"		 press 4 for checking for strong number"<<endl;
		cout<<"\n"<<endl;
		cin>>inputer;
		int input;
		cout<<"Enter the number to be check"<<endl;
		cin>>input;
		if(inputer==1)
		{
			perfect_number(input);
		}
		else if(inputer == 2)
		{
			amstrong_number(input);
		}
		else if(inputer== 3 )
		{
			prime_number(input);

		}
		else if(inputer == 4)
			strong_number(input);

		else if(inputer==5)
		{
			powerof2(input);
		}
		else
			return 0;
		
	}

}
