//3 - connected

#include<iostream>
#include<cstdlib>
#define MAX 50
using namespace std;

int n,edge[100][2],q[MAX],adj[100][100],reach[100],visit[100];
int rear=-1,front=-1;
int l[MAX],t=0,flag=0,value,truth=0,valid=1,ap=0;
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

int min(int x,int y)
{
  if(x<y)
    return x;
  else
   return y;
}

int apu(int u,int sadj[][100])
{
 // int t;
  visit[u]=1;
  int child=0;
  dfn[u]=low[u]=++tr;
 // cout<<"t="<<t<<endl;
 for(int j=0;j<n;j++)
  {
    if(sadj[u][j]==1)
     {
       int v=j;
       if(visit[v]!=1)
        {
          child++;
          parent[v]=u;
          apu(v,sadj);
          low[u]=min(low[u],low[v]);
          if(parent[u]==-1 && child>1)
             ar[u]=1;
          else if(parent[u]!=-1 && low[v]>=dfn[u])
            { ar[u]=1;
              // cout<<"u="<<u<<" ";
            }
        }
      else if (v != parent[u])
            low[u]  = min(low[u], dfn[v]);     
     } 
  }
  if(ar[u]==1)
  {
   return 1;//Whenever there is an articulation pt
  }
}

//To  check if graph is disconnected or not
int bfs(int v,int sadj[][100],int p1,int p2)
{
 enqueue(v);
 int count=0,i;
 reach[v]=1;
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
    //bfsedge[r][0]=cur;
    //bfsedge[r++][1]=i;
    
    reach[i]=1; 
    ++count;
   }
  }
  cout<<endl;
 }
 flag=0;
 for(i=0;i<n;i++)
 {
  if(reach[i]==0)
  { 
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  cout<<"\nDisconnected Graph...with vertex "<<i<<endl;
  valid=0;
  return 1;
 }
 else if(flag==0)
 {
  value=0;
  for(int i=0;i<n;i++)
    reach[i]=0;
  for (int i = 0; i < n; i++)
    {   if(i!=p1 && i!=p2 && reach[i] ==0)
        {
          value= apu(i,sadj);
          if(value==1)
           break;
        } 
    }
  if(value==1)
  {
   cout<<"\nThere is an Articulation Point\n";
   ap=1;
   return 0;
  }
 }
}

void check(int sadj[][100])
{
 int f=0,fg;
 for(int i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
  for(int rt=0;rt<n;rt++)
   for(int kt=0;kt<n;kt++)
    sadj[rt][kt]=adj[rt][kt];
    
   for(int k=0;k<n;k++)
   {
    if(i!=k)
    {
     sadj[i][k]=0;	
     sadj[k][i]=0;
    }
    if(j!=k)
    {
     sadj[j][k]=0;
     sadj[k][j]=0;
    }
   }
    int rr= bfs(0,sadj,i,j);
    if(rr==0)
     { f=1;}
   }
  }
  if(f==0)
   ap=0;
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
    parent[i]=-1;
  for(int i=0;i<n;i++)
     ar[i]=0;
 check(sadj);
 if((valid==1 && ap==0)||(valid==0 && ap==1)||(valid==0 && ap==0))
  cout<<"\nNot 3-Connected\n";
 else if(valid==1 && ap==1)
  cout<<"\n3-connected\n";  
 return 0;
}
