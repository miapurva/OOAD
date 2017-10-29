#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int binsearch(int arr[],int SIZE,int x)
{
	//int a[SIZE];
	int beg=0,mid,flag=0,end=SIZE-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(x==arr[mid])
		{
			flag=1;
			break;
		}
		else if(x<arr[mid])
			end=mid-1;
		else
			beg=mid+1;
	}
	if(flag==1)
	{
		//cout<<"Match found\n";
		return(x);
	}
	else if(flag==0)
	{
		//cout<<"No match found\n";
		return(0);
	}
}

int main(void)
{
	int SIZE;
	cout<<"\n\t\t\t\tWELCOME\n";
	cout<<"\tEnter the size of array\n";
	cin>>SIZE;
	cout<<"\t\t\tEnter the nos. in sorted array\n"<<endl;
	int arr[SIZE];
	for(int i=0;i<SIZE;i++)
	{
	cout<<"Enter the nos.:\t";
	cin>>arr[i];
																																																																																																																		
	}
	for(int i=0;i<SIZE;i++)
	{
		for(int j=i;j<SIZE;j++)
			{
				int sum=arr[i]+arr[j];
				if(binsearch(arr,SIZE,sum))
					cout<<"\n\tThe sum of "<<arr[i]<<" and "<<arr[j]<<" was found"<<endl<<"\tThat is "<<arr[i]+arr[j]<<" present in the array"<<endl;
				else
					cout<<"\nThe sum of "<<arr[i]<<" and "<<arr[j]<<" could not found."<<endl;
			}
	}
	
				
	return(0);
}

