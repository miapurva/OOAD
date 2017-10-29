#include <iostream>
#include <cstdlib>
using namespace std;
#define d 50

int abc(int x,int deno[],int no_of_deno)
{
	int quot,rem[d],i,k,r=0,sum=0;
	rem[0]={x};
	//int res[x]={0};
	//int l=0;
	int res[x];
	X:for(i=0;i<no_of_deno;i++)
	{
		for(int l=0;l<x;l++)
		
		{
			quot=x/deno[i];
			if(quot<1)
				continue;
			else
				sum=quot;
			res[l++]=sum;
			{
				LOOP:while(r<d)
				{	
					rem[r++]=rem[r]%deno[i];
					if(rem[r++]==0)
						goto X;
					for(int j=i+1;j<no_of_deno;j++)
					{
						for(int l=0;l<x;l++)
			
						{
						k=rem[r++]/deno[j];
						if(k<1)
							continue;
						else
							sum=k;
						sum=sum+res[l];
					r++;
					res[l]=-1;
				sum=sum+res[l];
				cout<<"\n result"<<res[l++]<<endl;
				cout<<"\nSum:\t"<<sum<<"\n";
					goto LOOP;
						
						}
					}
					
				}
			}
			
		}
		
	}
		
	
}


int main(void)
{
	int no_of_deno,i,x,b;

	cout<<"\n Enter value of x"<<endl;
	cin>>x;

	cout<<"\nEnter the no. of denominations"<<endl;
	cin>>no_of_deno;

	int deno[no_of_deno];

	for(i=0;i<no_of_deno;i++)
	{
		cout<<"\nEnter the denomination\n";
		cin>>deno[i];
	}

b=abc(x,deno,no_of_deno);

return(0);
}
