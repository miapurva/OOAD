#include<iostream>
#include<cstdlib>
using namespace std;

int gcd(int a, int b)
{
	
	if(b==0)
		return a;
	else
		return(gcd(b,a%b));
}
int maxie,minie;
int gcd1(int a,int b)
{
	
	if(a>b)
	{
		maxie=a;
		minie=b;
	}
	else
	{
		maxie=b;
		minie=a;
	}
}

int main(void)
{
int k,i;
	cout<<"Enter the nos. you want to check gcd for:\n";
	cin>>k;

	if(k==2)
	{
		int a,b;
		cout<<"Enter two integers\n";
		//a=rand()%50;
		//b=rand()%50;
		cin>>a>>b;
		int t;
		t=gcd(a,b);
		cout<<"GCD \t"<<t;
		

	}
	else if(k>2)
	{
		int c[k];
		int result,result1;
		for(i=0;i<k;i++)
		{
			cout<<"Enter the no.\n";
			cin>>c[i];
		}
		for(i=0;i+2<k;i++)
		{	
			gcd1(c[i],c[i+1]);
			result=gcd(maxie,minie);
			gcd1(result,c[i+2]);
			result1=gcd(maxie,minie);
		}
			
			cout<<"GCD \t"<<result1;
	}
return(0);
}
