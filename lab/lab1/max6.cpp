/* using average of array */

#include <iostream>
#include <stdlib.h>
using namespace std;

//FINDING AVERAGE
int avrg(int a[],int n)
{
	int i,sum=0,ctr=0;

    //takes only non zero elements while counting average
	for(i=0;i<n;i++)
		if(a[i]!=0)
			ctr++;
	for(i=0;i<n;i++)
		sum+=a[i];

	return(sum/ctr);
}

//checks the array if there is only maximum and zero
int check_array(int a[],int n,int avg)
{
	int i;

	for(i=0;i<n;i++)
		if(a[i]!=0 && a[i]!=avg)
			return 0;

	return 1;
}

//changes all numbers less than zero to zero
void change_array(int a[],int n,int avg)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]<avg)
			a[i]=0;
}

int main(void)
{
	int n,max,avg,flag;
	int a[10],i,j,b[10];
	srand(time(NULL));
	cout<<"Enter the size of array: ";
	cin>>n;
	n=rand()%100;

	for(i=0;i<10;i++)
		a[i]=rand()%100;
	//copy a
	for(i=0;i<10;i++)
		b[i]=a[i];

	do
	{
		avg=avrg(a,10);
		change_array(a,10,avg);
	}	
	while(check_array(a,10,avg)!=1);


	cout<<"ARRAY: ";
	for(i=0;i<10;i++)
	{
		cout<<b[i]<<" ";
		if(a[i]!=0)
			max=a[i];
	}
	cout<<"\n"<<"MAX:\t "<<max<<"\n";
return(0);
}
