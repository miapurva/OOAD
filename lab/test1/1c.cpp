#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>

void merge(int arr[], int start_index, int midend_index, int end_index)
{
    int i, j, k;
    int n1 = midend_index-start_index+1;
    int n2 =  end_index-midend_index;
 

    int L[n1], R[n2];			//creating two arrays

    for (i=0;i<n1;i++)
        L[i] = arr[start_index + i];
    for (j=0;j<n2;j++)
        R[j] = arr[midend_index+1+j];
 
    i = 0; 
    j = 0; 
    k = start_index; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergesort(int arr[], int start_index, int end_index)
{
    if (start_index < end_index)
    {
       
        int midend_index = start_index+(end_index-start_index)/2;
 
        mergesort(arr, start_index, midend_index);
        mergesort(arr, midend_index+1, end_index);
 
        merge(arr, start_index, midend_index, end_index);
    }
}

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
	int SIZE,z,flag=0;
	int t=1,i=0;
	cout<<"Enter the size of the array"<<endl;
	cin>>SIZE;
	int arr[SIZE];
	for(i=0;i<SIZE;i++)
	{
		cout<<"\n Enter the nos:\t";
		cin>>arr[i];
	}		
	cout<<"Enter the value for z"<<endl;
	cin>>z;
	
	//int g=0;
	mergesort(arr,0,SIZE-1);
	
	while(t)
	{
	for(int i=0;i<SIZE;i++)	
		{
			if(binsearch(arr,SIZE,i) && binsearch(arr,SIZE,z-i))
			{
                            cout<<"\n"<<i<<" "<<z-i<<endl;
                            flag=1;
                            break;
                   	}
                   
		}
			if(flag==0)
			cout<<"FAILURE"<<endl;
			
			else
			{
			cout<<"SUCCESS";
			cout<<endl;
			}
	return(flag);
			
return(0);			
}
}

	


