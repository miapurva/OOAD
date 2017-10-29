//BUBBLE SORT

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(void)
{
srand(time(NULL));
int n,i,temp,j;
cout<<"\n\t\t\tBUBBLE SORT\n";
n=rand()%10;
cout<<"The size of array";
cout<<n;

int a[n];
for(i=0;i<n;i++)
{
	cout<<"\nEnter the integer\n";
	for(i=0;i<n;i++)
	{a[i]=rand()%50;
	cout<<a[i]<<"\n";}
}
for(i=0;i<n-1;i++)
{
  for(j=0;j<n-1-i;j++)
   {					//SWAPPING
    if(a[j]>a[j+1])
     {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
     }
   }
}
//for(i=0;i<n;i++)
cout<<"\n MAX: "<<a[n-1];

return(0);
}
