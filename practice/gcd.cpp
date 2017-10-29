//GCD 

#include<iostream>

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
{	int k,i;
	cout<<"Enter the nos. you want to check gcd for:\n";
	cin>>k;

	if(k==2)
	{
		int a,b;
		cout<<"Enter two integers\n";
		cin>>a>>b;
		int t;
		t=gcd(a,b);
		cout<<"GCD \t"<<t;
		

	}
	else if(k>2)
	{
		int a[k];
		int result,result1;
		for(i=0;i<k;i++)
		{
			cout<<"Enter the no.\n";
			cin>>a[i];
		}
		for(i=0;i+2<k;i++)
		{	
			gcd1(a[i],a[i+1]);
			result=gcd(maxie,minie);
			gcd1(result,a[i+2]);
			result1=gcd(maxie,minie);
		}
			//result1=gcd(maxie,minie);
			cout<<result1;
	}
return (0);
}

