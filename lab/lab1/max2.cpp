//NORMAL CHECKING IF THE PREVIOUS NO. IS GREATER THAN NEXT NO.

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	int n,i;
	cout<<"\n\t\t\tNORMAL CHECK USING FOR LOOP\n";
	cout<<"Enter the array size\n";
	n=rand()%10;
	cout<<n;
	int a[n];

	for(i=0;i<n;i++)
	{
		cout<<"\nThe nos. are:\n";
		for(i=0;i<n;i++)
		{
			a[i]=rand()%70;
			cout<<a[i]<<"\n";
		}
	}
	int max;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}

	cout<<"\nMax:"<<max;
	cout<<"\n";
	return(0);
}
