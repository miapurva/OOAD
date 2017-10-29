//DIVIDING THE ARRAY INTO HALF, FINDING MAX SEPARATELY AND THEN COMPARAING BOTH THE MAX FROM THE ARRAY

#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>

int main(void)
{
	srand(time(NULL));
	int n,i,j,k;
	cout<<"The size of array\n";
	n=rand()%10;
	cout<<n<<"\n";
	int a[n];
	cout<<"The numbers are\n";
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<"\n";
	}
for(i=0;i<n/2;i++)
{
	j=a[0];
	if(a[i]>j)
		j=a[i];
}
for(i=n/2;i<n;i++)
{
	k=a[n/2];
	if(a[i]>k)
		k=a[i];
}

if(j<k)
	cout<<"MAX\t"<<k<<"\n";
else
	cout<<"MAX\t"<<j<<"\n";
return(0);
}
