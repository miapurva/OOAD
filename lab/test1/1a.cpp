#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>

int goldbach(int A[], int z)
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
