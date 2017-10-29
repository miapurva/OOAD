#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>

int isprime(long long int x)
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

int goldbach(long long int x)
{
     
	int flag=0;
	if(x<4)
		cout<<"\n Number less than 4";
	else if(x>=4)
	{
		for(int i=2;i<x/2;i++)	
		{
			if(isprime(i) && isprime(x-i))
			{
				cout<<"\nPrime nos. are \t"<<i<<"+"<<(x-i)<<"\n";
                            flag=1;
                     }	
		      /* else if(!isprime(i) && !isprime(x-i))
			{
				cout<<"\n\t\tConjecture is false for and numbers above "<<x<<endl;
				break;
			}*/
		}
		return flag;				
	}
}

int main(void)
{
	//srand(time(NULL));
	long long int x,i=4;
	cout<<"\n\t\t\tGoldbach Conjecture:\t";
	while(goldbach(i))
	{
			cout<<a[i]<<endl;
			goldbach(a,i);

	}
	

	return(0);
}
//Largest number = 4*10^8
