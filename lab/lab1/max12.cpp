//HEAP

#include<iostream>
#include<cstdlib>
#include<ctime>
#define SIZE 50
using namespace std;


int heap[SIZE];
int count=0;

void insert(int key)
{
 if(count>=SIZE)
  cout<<"HEAP IS FULL";
 else{
 count++;
 heap[count]=key;
 int i=count;
 while(i>0 && heap[i/2] > key)
 {
  heap[i]=heap[i/2];
  i=i/2;
 }
  heap[i]=key;
}
}

int del_min()
{
 int last=heap[count--];
 int min=heap[1];
 int i,child;
 for(i=1; i*2 <= count;i=child)
 {
  child=i*2;
  if(heap[child] !=last && heap[child+1]<heap[child])
   child++;
  if(heap[child]<last)
    heap[i]=heap[child] ;
  else
    break;
  }
  heap[i]=last;
  return min;
 }
 
int main(void)
{
srand(time(NULL));
 int n;
 cout<<"\n\t\t\tHEAP\n";
 cout<<"\nThe number of elements to insert:";
 n=rand()%10;
 int i=0,key;
 while(i<n)
 {
  cout<<"\nThe key:";
  key=rand()%100;
  cout<<key;
  insert(key);
  i=i+1;
 }
 cout<<"\nHEAP SORT:";
 int b[n];
 i=0;
 while(i<n) 
 {
  b[i]=del_min();
  i=i+1;
 }
 /*for(i=0;i<n;i++)
  cout<<b[i]<<"\n";
 cout<<"\n";*/
 
 cout<<"Max:\t"<<b[n-1];
 return(0);
}
