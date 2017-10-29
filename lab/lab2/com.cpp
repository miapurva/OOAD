#include <iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

int main(void)
{
	int i,j,c,r,k;
	srand(time(NULL));
	cout<<"The size of set is\n";
	cin>>r;
	int z[r];
	
	
	cout<<"The nos. in the set are"<<endl;
	for(i=0;i<r;i++)
	{
		z[i]=rand()%15;
		cout<<z[i]<<endl;
	}
	
	cout<<"Enter the size of subset (2||3)\n";
	cin>>k;
	cout<<"\n";
	if(k==2)
	{
		for(i=0;i<r;i++)
		{
			for(j=i+1;j<r;j++)
			{
				cout<<"\n"<<z[i]<<","<<z[j]<<endl;
			}
		}	
	}
	else if(k==3)
	{
		for(i=0;i<r;i++)
		{
			for(j=i+1;j<r;j++)
			{
				for(c=j+1;c<r;c++)
				{
					cout<<"\n"<<z[i]<<","<<z[j]<<","<<z[c]<<endl;
				}			
			}
		}	
	}
	else
	{cout<<"Enter a valid operator"<<endl;
	exit(0);
	}
	return(0);
}

