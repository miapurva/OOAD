#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int fib(int n)
{
	if(n==0 || n==1)
		return n; 
	return(fib(n-1) + fib(n-2));
}

int countways(int n)
{
	return(fib(n+1));
}

int main(void)
{
int x;
cout<<"\n\t\t\t MONKEY PROBLEM\nEnter the number of steps:\t";
cin>>x;
cout<<"No. of ways:\n"<<countways(x);
cout<<"\n";
return(0);
}
