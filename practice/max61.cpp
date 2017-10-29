//USING AVERAGE


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int k;
float avg;
/*void changearray(int a[k])
{
for(int i=0;i<k;i++)
{
	if(avg<a[i])
	{
		a[i]=0;
	}
	else if(avg>a[i])
	{
	cout<<"\nEntered loop i\n";
	cout<<a[i];
	}
	
}
}

void average(int a[k])
{
int sum;
for(int i=0;i<k;i++)
{
	sum=sum+a[i];
}
avg=sum/k;
}*/

int main(void)
{
srand(time(NULL));
cout<<"\n\t\t\tFINDING MAX USING AVERAGE\n";
cout<<"\nEnter the size of array:\t";
cin>>k;
//cout<<k;
int a[k];

cout<<"The nos. are";
for(int i=0;i<k;i++)
{
	a[i]=rand()%100;
	cout<<"\n"<<a[i];
}

//average(a[k]);
int sum=0,count=0,r,flag=0;
while(flag==0)
{
for(int i=0;i<k;i++)
{
	sum=sum+a[i];
}

avg=sum/r;
//changearray(a[k]);
for(int i=0;i<k;i++)
{
	if(avg>a[i] && a[i]!=0)
	{       
		a[i]=0;
		count=count+1;
		if(count==k-1)
		{   
		    flag=1;
		    break;
		}
	}

	if(avg<a[i])
	{
		{
		cout<<"\nEntered loop "<<i<<"\n";
		cout<<a[i];
		cout<<"\n";
		}
	}
		
}	
r=k-count;
}

/*cout<<"\n\nMAX:\t";
for(int i=0;i<k;i++)
{
   if(a[i]!=0)
   {
      cout<<a[i];
   }

}*/
return(0);
}
