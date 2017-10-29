#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>

int isprime(int x)
{
	for(int i=2;i<x/2;i++)
	{
		if(x%i==0)
		{	
			return 0;
		}
	}
	return 1;	
}

int goldbach(int x)
{
     
	int flag=0;
	/*if(x<4)
		cout<<"\n Number less than 4";*/
	if(x>=4)
	{
		for(int i=2;i<=x/2;i++)	
		{
			if(isprime(i) && isprime(x-i))
			{
                            flag=1;
                            break;
                     }	
		}
		if(flag==0){
			cout<<endl;
			cout<<"FAILURE"<<x;
		}
		else
			cout<<x<<" ";
		return flag;				
	}
}

int main(void)
{
	//srand(time(NULL));
	int i=4;
	int t=1;
	cout<<"\n\t\t\tGoldbach Conjecture:\t";
	while(t)
	{
	  t=goldbach(i);
	  i=i+2;
	}
	return(0);
}
//Largest number = 4*10^18
