#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(void)
{
srand(time(NULL));
int k,c=1;
int b[k+1],i;
cout<<"The size of array:\t";
k=rand()%10;
cout<<k<<"\n";

cout<<"\nThe nos. are:\n";
for(i=0;i<k;i++)
{
b[i]=rand()%100;
cout<<b[i]<<"\n";
}

for(i=0;i<k;i++)
{
c=i+1;
int temp=b[i];
while(c>1 && b[c/2]>temp)
{
	b[c]=b[c/2];
	c/=2;
}
b[c]=temp;
}
cout<<"\n Max:\t"<<b[1]<<"\n";
return(0);
}
