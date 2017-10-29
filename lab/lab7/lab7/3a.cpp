
//shortest cycle

#include<iostream>
#include<cstdlib>
#define MAX 50
using namespace std;

int n,edge[100][2],q[MAX],adj[100][100],reach[100],visit[100];
int rear=-1,front=-1;
int l[MAX],t=0,flag=0,value,truth=0,valid=0;
int parent[100],dfn[100],low[100],ar[100],tr=0;

void enqueue(int v)
{
 if(rear== MAX -1)
  cout<<"\nQueue is full";
 else
 {
  if(front==-1 && rear==-1)
   front=0;
  q[++rear]=v;
 }
}

int queueempty()
{
 if(front==-1 || front>rear)
   return -1;
}

int dequeue()
{
 if(queueempty()==-1)
  return -1;
 if(front == rear)
 {
  int temp=q[front];
  front=-1;
  rear=-1;
  return temp;
 }
  int temp=q[front++];
  return temp;
}

void bfs(int v,int sadj[][100])
{
 enqueue(v);
 int i;
 reach[v]=1;
 for(int i=0;i<n;i++)
  l[i]=1000;
 l[v]=0;
 cout<<endl;
 cout<<v<<endl;
 while(queueempty() != -1)
 {
  int cur=dequeue();
  for(i=0;i<n;i++)
  {
   cout<<"\t";
   if(sadj[i][cur]==1 && reach[i]==0)
   {
    l[i]=l[cur]+1;
    cout<<i<<" "<<l[i];
    enqueue(i);
    reach[i]=1; 
    //++count;
   }
  }
  cout<<endl;
 }
}

int minin(int ar[],int c)
{
 int mini=ar[0];
 for(int i=1;i<c;i++)
 {
  if(ar[i]<mini)
   mini=ar[i];
 }
 cout<<"\nar : \n";
 for(int i=0;i<c;i++)
  cout<<ar[i]<<" ";
 cout<<endl;
 return mini;
}

int gen(int sadj[][100])
{
 int a,b,count=0;
 cout<<"\nNumber of edges : "<<t<<endl;
 for(int i=0;i<t;i++)
 {
  for(int j=0;j<n;j++)
   for(int k=0;k<n;k++)
    sadj[j][k]=adj[j][k];
  for(int rt=0;rt<n;rt++)
   reach[rt]=0;
  
  a=edge[i][0];
  b=edge[i][1];
  sadj[a][b]=0;//Checking the shortest path(u,v) by removing u-v
  sadj[b][a]=0;
  for(int j=0;j<n;j++)
  {
   for(int k=0;k<n;k++)
    cout<<sadj[j][k]<<" ";
   cout<<endl;
  } 
  bfs(a,sadj);//Shortest path b/w u and v
  ar[count++]=l[b]+1;
 }
 return minin(ar,count);
}

int main(void)
{
 cout<<"\nEnter number of vertices: ";
 cin>>n;
 int i,a,b;
 int sadj[100][100];
 srand(time(NULL));
 do
 {
 cout<<"\nEnter the edges:"; 
 cin>>a>>b;
 edge[t][0]=a;
 edge[t++][1]=b;
 adj[a][b]=1;
 sadj[a][b]=1;
 sadj[b][a]=1;
 adj[b][a]=adj[a][b];
 cout<<"\nEnter 1 to exit:";
 cin>>i;
 if(i==1)
  break;
 }while(1);
 /*for(int i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
   adj[a][b]=rand()%2;
   adj[b][a]=adj[a][b];
  }
 }*/
 for(int i=0;i<t;i++)
  cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
 for(int i=0;i<n;i++)
  adj[i][i]=-1;
 for(int i=0;i<n;i++)
  reach[i]=0;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
   cout<<adj[i][j]<<" ";
  cout<<endl;
 }
  for(int i=0;i<n;i++)
     ar[i]=0;//Min distance between any to edges
 cout<<"\nShortest cycle : "<<gen(sadj)<<endl;
 return 0;
}
