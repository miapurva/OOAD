#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>
 
int main(void)
{
int temp,n=7,i,c,count=0,j;
clock_t start,end,sum=0;
//printf("Enter the array size\n");
//scanf("%d", &n);

int a[n];

start=clock();
for(c=1;c<=100;c++)
{
	cout<<"\nRandom array :"<<c<<"\t";
	for(i=0;i<n;++i)
	{
		a[i]=rand()%100;
		cout<<"\t"<<a[i];
	}

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
		    if(a[j]>a[j+1])
		     {
		     	if(c==1)
					count++;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
		     }
		}
	}
	cout<<"\nSorted array\t\t";
	for(i=0;i<n;++i)
	cout<<"\t"<<a[i];
}
end=clock();
sum+=(end-start);
long double time=(long double)sum/(CLOCKS_PER_SEC*100);
cout<<"\n"<<"Average Time\t"<<time<<endl;
cout<<"\n"<<"Count\t"<<count;
return(0);
}
