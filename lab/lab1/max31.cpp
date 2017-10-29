//USING DIVISION

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int n=10;

int max(int a[][3],int n)
{
	int i,j,k,max;
	for(i=0;i<n;i++)
		a[i][0]=a[i][0]+100;
	for(i=0;i<n;i++)
	{
		if(a[i][0]==0)					//IF THE INPUT ITSELF IS ZERO 
			continue;
		for(j=0;j<n;j++)
		{
			if(a[j][0]!=0)
			{
				a[j][1]=a[j][0]/a[i][0];
				if(a[j][1]==0)			//QUOTIENT IS ZERO 
					a[j][0]=0;		//MAKING THE NO. ZERO
			}
			/*else
			a[j][1]=0;*/
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(a[i][1]==1)					//QUOTIENT IS NOT ZERO(FOR MAX NO.)
		{
			max=a[i][0];				//MAX NO.
			break;
		}

	}
	return max-100;
}


int main(void)
{
	int a[10][3];
	srand(time(NULL));
	cout<<"\n\t\t\tFINDING MAX USING DIFFERENCE\n";
	cout<<"\n The nos. are";
	for(int i=0;i<n;i++)
	{
		a[i][0]=rand()%100;
		cout<<"\n"<<a[i][0];
	}
	cout<<"\n MAX :"<<max(a,10)<<"\n";


	return(0);
}
