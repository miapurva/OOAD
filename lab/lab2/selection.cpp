#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

int main(void)
{
	srand(time(NULL));
	clock_t start,end,sum=0;

	int n,i,max,pmax=0,c,temp,count=0,j;
	/*cout<<"The array size\n";
	n=rand()%10;
	cout<<n<<endl;*/

	int a[7];
	//cout<<"The randomly generated nos. are \n";

	start=clock();
	for(c=1;c<=100;c++)									
	{
		cout<<"\nThe array is:\t"<<c;
		for(i=0;i<7;i++)								
		{
			a[i]=rand()%100;							
			cout<<"\t"<<a[i];
		}
		for(i=0;i<7-1;i++)								
		{
			pmax=i;
			for(j=i+1;j<7;j++)							
			{
				  if(a[pmax]>a[j])
				     {
					pmax=j;
					if(c==1)
					count++;
				     }
			}
			if(pmax!=i)
			{
				temp=a[i];
				a[i]=a[pmax];
				a[pmax]=temp;
			}
		}
		cout<<"\n"<<"Sorted order:";
		for(i=0;i<7;++i)
		cout<<"\t"<<a[i];
	}
	end=clock();
	sum+=(end-start);
	long double time=(long double)sum/(CLOCKS_PER_SEC*100);
	
	cout<<"\nAverage time\n"<<time<<endl;
	cout<<"\n"<<"Count\t"<<count;
	return(0);
}
