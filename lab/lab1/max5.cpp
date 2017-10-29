//Using Subtraction
//Finding the difference with first no.

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(void)
{
srand(time(NULL));
int a[10];
int i,t,k=10;
cout<<"\n\t\t\tFINDING DIFFERENCE WITH THE FIRST NO.\n";
for(i=0;i<k;i++)
{a[i]=rand()%100;
cout<<a[i]<<"\t"<<"\n";
}

int b[k];

for(int t=0;t<k;t++)
b[t]=a[t];		//copying in another array

int x=b[0];
for(i=0;i<k;i++)
b[i]=x-b[i];		//Creating an array by subtraction of negative nos.

int min=b[0];
for(i=0;i<k;i++)
if(b[i]<min)
min=b[i];		//fetching the smallest negative no. of the array

cout<<"MAX:\t"<<x-min<<"\n";		//subtracting the most -ve no. from the least -ve no(the first no. of the array)

return(0);
}
