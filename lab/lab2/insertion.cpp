#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

int main(void)
{
	int n=7,i,max,c,count=0,pmax,temp,j;
	//cout<<"Enter the array size\n";
	clock_t start,end,sum=0;
	int a[n];
	start=clock();
	for(int c=1;c<=100;c++)
	{
	cout<<"\nRandom array\t";
	for(i=0;i<n;++i)
	{
		a[i]=rand()%100;
		cout<<"\t"<<a[i];
	}

	//insertion sort
	for(i=1;i<n;++i)
	{
		temp=a[i];
	for(j=i-1;j>=0;--j)
	{

		if(a[j]>temp)
			a[j+1]=a[j];
			if(c==1)
				count++;
		else 
			break;
	}
	a[j+1]=temp;
	}
	cout<<"\nSorted order:\t";
	for(i=0;i<n;++i)
		cout<<"\t"<<a[i];
	}
	end=clock();
	sum+=(end-start);
	long double time=(long double)sum/(CLOCKS_PER_SEC*100);
	cout<<"\nAverage time\n"<<time<<endl;
	cout<<"\n"<<"Count\t"<<count;
	return(0);
}
