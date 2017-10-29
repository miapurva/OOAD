#include<iostream>
#include<cstdlib>
using namespace std;
//Addition-Subtraction
void swap(float a, float b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"\n";
	cout<<a<<"\t";
	cout<<b<<"\n";
}

/*void swap2(char c[50], char d[50])
{	//char c[50],d[50];
	int i=0;
		while(c[i]!='\0' && d[i]!='\0')
		{
			c[i]=c[i]^d[i];
			d[i]=c[i]^d[i];
			c[i]=c[i]^d[i];
			i++;
		}

	cout<<"\n";
	cout<<c<<"\t";
	cout<<d;
	cout<<"\n";
}*/
//Using Temporary Variable
void swap3(float a,float b)
{	
float temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"\n";
	cout<<a<<"\t";
	cout<<b<<"\n";
}

int main(void)
{
int i=0,n;
float a,b;


while(1)
{
cout<<"\n Choose \n1.(Add-Subtract)\n 2.(EX-OR)\n 3. (Temp)\n 4.Exit\n";
cin>>n;
switch(n)
{
case 1:cout<<"\nThe two nos:\t";
	cin>>a>>b;
	swap(a,b);
	break;

//Ex-Or
case 2:char c[50],d[50];
	cout<<"\nThe two nos:\t";
	cin>>c>>d;
	while(c[i]!='\0' && d[i]!='\0')
	{
		c[i]=c[i]^d[i];
		d[i]=c[i]^d[i];
		c[i]=c[i]^d[i];
		i++;
	}
	cout<<"\n";
	cout<<c<<"\t";
	cout<<d;
	cout<<"\n";
	//swap2(a,b);
	break;
case 3: cout<<"\nThe two nos:\t";
	cin>>a>>b;
	swap3(a,b);
	break;

case 4: exit(0);
	break;
}
}
return(0);
}
