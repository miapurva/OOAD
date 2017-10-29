#include<iostream>
#include<cstdlib>
using namespace std;
char temp;
//Addition-Subtraction
void swap(char a, char b)
{
	a=a+b;					
	b=a-b;
	a=a-b;
	cout<<"\n";
	cout<<a<<"\t";
	cout<<b<<"\n";
}
//Ex-Or
void swap2(char a, char b)
{
	a=a^b;
	b=a^b;
	a=a^b;
	cout<<"\n";
	cout<<a<<"\t";
	cout<<b;
	cout<<"\n";
}
//Using Temporary Variable
void swap3(char a,char b)
{
	temp=a;
	a=b;
	b=temp;
	cout<<"\n";
	cout<<a<<"\t";
	cout<<b<<"\n";
}

int main(void)
{
int n;
char a,b;

cout<<"\nEnter two characters:\t";
cin>>a>>b;



while(1)
{
cout<<"\n Choose \n1.(Add-Subtract)\n 2.(EX-OR)\n 3. (Temp)\n 4.Exit\n";
cin>>n;
switch(n)
{
case 1:swap(a,b);
	break;

case 2:swap2(a,b);
	break;
case 3: swap3(a,b);
	break;

case 4: exit(0);
	break;
}
}
return(0);
}
