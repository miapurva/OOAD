#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

void insertion(int a[],int n)
{	
	int i,j,temp;
	for(i=1;i<n;++i)
	{
		temp=a[i];
	for(j=i-1;j>=0;--j)
	{

		if(a[j]>temp)
			a[j+1]=a[j];
		else 
			break;
	}
	a[j+1]=temp;
	}
}

void selection(int a[], int n)
{
	int i,j,pmax,temp;
		for(i=0;i<n-1;i++)
		{
			pmax=i;
			for(j=i+1;j<n;j++)
			{
				  if(a[pmax]>a[j])
				     {
					pmax=j;
				     }
			}
			if(pmax!=i)
			{
				temp=a[i];
				a[i]=a[pmax];
				a[pmax]=temp;
			}
		}
}

void bubble(int a[], int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
		    if(a[j]>a[j+1])
		     {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
		     }
		}
	}
}

int main(void)
{
	srand(time(NULL));
	clock_t start,end,sum=0,sum1=0,sum2=0;
	int n=7,i,j,c;
	int a[n];
	//bubble
	start=clock();
	for(c=1;c<=100;c++)
	{
	//cout<<"\nThe array is:\t"<<c;
		for(i=0;i<7;i++)
		{
			a[i]=rand()%100;
			//cout<<"\t"<<a[i];
		}
		bubble(a,n);
	/*cout<<"\nSorted array\t\t";
	for(i=0;i<n;++i)
		cout<<"\t"<<a[i];*/
	}
	end=clock();
	sum+=(end-start);
	long double time=(long double)sum/(CLOCKS_PER_SEC*100);
	cout<<"\n"<<"Average Time\t"<<time<<endl;
	
	//insertion
	start=clock();
	for(c=1;c<=100;c++)
	{
	//cout<<"\nThe array is:\t"<<c;
		for(i=0;i<7;i++)
		{
			a[i]=rand()%100;
			//cout<<"\t"<<a[i];
		}
		insertion(a,n);
	/*cout<<"\nSorted array\t\t";
	for(i=0;i<n;++i)
		cout<<"\t"<<a[i];*/
	}
	end=clock();
	sum1+=(end-start);
	long double time1=(long double)sum1/(CLOCKS_PER_SEC*100);
	cout<<"\n"<<"Average Time\t"<<time1<<endl;
	//selection
	start=clock();
	for(c=1;c<=100;c++)
	{
	//cout<<"\nThe array is:\t"<<c;
		for(i=0;i<7;i++)
		{
			a[i]=rand()%100;
			//cout<<"\t"<<a[i];
		}
		selection(a,n);
	/*cout<<"\nSorted array\t\t";
	for(i=0;i<n;++i)
		cout<<"\t"<<a[i];*/
	}
	end=clock();
	sum2+=(end-start);
	long double time2=(long double)sum2/(CLOCKS_PER_SEC*100);
	cout<<"\n"<<"Average Time\t"<<time2<<endl;
	
	long double maxxx,maxx;
	if(time>time1)
	maxx=time;
	else
	maxx=time1;
	if(maxx>time2)
	maxxx=maxx;
	else
	maxxx=time2;
	cout<<"\n\nBest average time\t"<<maxxx<<endl;
	
	return(0);
}
