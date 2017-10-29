#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
#define SIZE 1000

int waysearch2(int arr[1000],int searchelement)
{ 
int beg=0,mid,flag=0,end=SIZE-1;


while(beg<=end)
{
mid=(beg+end)/2;
if(searchelement==arr[mid])
{
flag=1;
break;
}
else if(searchelement<arr[mid])
end=mid-1;
else
beg=mid+1;
}

if(flag==1)
cout<<"Match found\n";
else if(flag==0)
cout<<"No match found\n";
return(0);
}

	int waysearch3(int arr[1000], int l, int r, int searchele)
{
   if (r >= l)
   {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;
 
           if (arr[mid1] == searchele)  return 1;
 
           if (arr[mid2] == searchele)  return 1;
 
          if (arr[mid1] > searchele) return waysearch3(arr, l, mid1-1, searchele);
 
           if (arr[mid2] < searchele) return waysearch3(arr, mid2+1, r, searchele);
 
           return waysearch3(arr, mid1+1, mid2-1, searchele);
   }
      return -1;

}


int main(void)
{	
	int op,searchelement;
	clock_t start,end,sum=0;
	srand(time(NULL));
	cout<<"\n\t\t\t WELCOME"<<endl;
	
	int arr[SIZE];
	cout<<"Enter the no.:\t";
	for(int c=1;c<=100;c++)
	{
	for(int i=0;i<SIZE;i++)
	{
		
		arr[i]=rand()%100;
		cout<<arr[i]<<endl;
	}
	}
	cout<<"Enter an int to search for\n";
	int k=rand()%SIZE;
	searchelement=arr[k];
	cout<<searchelement;	
	int t;
	long double time;
	while(1)
	{
		cout<<"\nEnter the option\n";
		cout<<"\t1.2way search \n\t\t2.waysearch3 \n\t\t\t3.waysearch \n\t\t\t\t4.EXIT";
		cin>>op;
	switch(op)
	{
		case 1:	
			start=clock();
				waysearch2(arr,searchelement);
			
		
			end=clock();
			sum+=(end-start);
			time=(long double)sum/(CLOCKS_PER_SEC*100);
			cout<<"\n"<<"Average Time\t"<<time<<endl;
			break;
		
		case 2:	start=clock();
		
			t=waysearch3(arr,0,999,searchelement);
			
			end=clock();
			if(t==-1)
			cout<<"No. not found"<<endl;
			else
			cout<<"No. found\n";
			sum+=(end-start);
			time=(long double)sum/(CLOCKS_PER_SEC*100);
			cout<<"\n"<<"Average Time\t"<<time<<endl;
			break;
		
		//case 3:t=waysearch4(arr,SIZE,searchelement);
			
		/*	if(t==-1)
			cout<<"NO. not found"<<endl;
			else
			cout<<"No. found"<<endl;
			break;
			*/
		//	break;
		case 4:exit(0);
	}
	}
	
	return(0);
}
