//Arranging in Descending order(BUBBLE SORT)

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(void)
{
srand(time(NULL));

int n,i,j,temp;
cout<<"Enter the array size\n";
n=rand()%10;
cout<<n;

int a[n];
for(i=0;i<n;i++)
{
cout<<"\nEnter the no.:\t";
for(i=0;i<n;i++)
{
a[i]=rand()%60;
cout<<a[i]<<"\n";
}
}
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]<a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
cout<<"Max no.:\t"<<a[0]<<"\n";
return(0);
}
			


