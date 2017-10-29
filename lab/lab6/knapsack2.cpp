#include <iostream>
#include <cstdlib>
using namespace std;

int weight[100],profit[100];

int max(int a, int b)
{
	cout<<"\n(a,b) : "<<a<<" "<<b<<endl;
	if(a>b)
	{
		cout<<"a "<<a;
		return a;
	}
	else
	{
		cout<<"b "<<b;
		return b;
	}
}

int knapsack(int n,int W)
{
	int arr[n+1][W+1];
	for (int i = 0; i <=n ; ++i)
            {
            	for (int w = 0; w<=W; w++)
            	{
            	
			arr[i][w]=0;							
				}
				cout<<endl;
			}
	//for(int w=0;w<=W;w++)
	//arr[0][w]=0;											//initializing it as 0
	for (int w = 0; w <= W; w++)
	{
		//cout<<arr[0][w];
		cout<<" i "<<0<<" ,w "<<w<<" "<<arr[0][w]<<endl;			//printing
	}
	int w;
	for(int i=1;i<=n;i++)
		for (w = 1; w <=W ; w++)
		{
			cout<<"i "<<i<<" ,w "<<w<<" "<<endl;
			if (w<weight[i])
			{
				cout<<"not included\n";
				//cout<<"i "<<i<<" ,w "<<w<<" "<<endl;//arr[i][w]<<endl;
				arr[i][w]=arr[i-1][w];
			}
			else
			{
				cout<<"included\n";
				//cout<<"i "<<i<<" ,w "<<w<<" "<<arr[i-1][w]<<endl;
				int inter;
				inter= w - (weight[i]);
				arr[i][w]=max(arr[i-1][w],profit[i]+arr[i-1][inter]);
			}
            cout<<"\nAfter operation:\n";
            for (int j = 0; j <=n ; j++)
            {
            	for (int x = 0; x<=W; x++)
            	{
            	
			      cout<<arr[j][x]<<" ";	
				}
				cout<<endl;
			}
			//cout<<"i "<<i<<" ,w "<<w<<" "<<arr[i][w]<<endl;
		}

		return arr[3][5];
}

int main(void)
{	
	int n,W;
	//int ;
	cout<<"\n\t\t\t DP for Knapsack\n";

	cout<<"Enter the no. of objects\n";
	cin>>n;
	
	cout<<"\nEnter the weights and corresponding profit:\t"<<endl;
	for (int i = 1; i <= n; i++)
	{
		cin>>weight[i];
		cin>>profit[i];
	}
	cout<<"\nEnter the maximum capacity of Knapsack"<<endl;
	cin>>W;


	int k=knapsack(n,W);

	cout<<"Knapsack "<<k<<endl;	

	return(0);
}