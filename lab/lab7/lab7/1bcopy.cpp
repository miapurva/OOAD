//TEST FOR C3 AND C4 AND LIST ALL OF THEM

#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAX 50
using namespace std;

int adj[50][50],n,q[MAX],reach[MAX];
int rear=-1,front=-1;
int l[MAX],last;
int start,flag;
int crossedge[50][2],missedge[100][2],c3[50][3],c4[100][4],h,z,found;
int bfsedge[100][2],r=0;
int edge[100][2],t=0,truth=0;

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

void print()
{
  for(int j=0;j<=last;j++)
  {
   cout<<j<<" : "<<endl;
   for(int i=0;i<n;i++)
   {
    if(l[i] == j)
     cout<<i<<" ";
   }
   cout<<endl;
  }
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

void check4()
{
 int a,b,up=0,fr=0;
 truth=0;
 cout<<"h : "<<h<<endl;
 for(int i=0;i<h;i++)
 {
  a=missedge[i][0];
  b=missedge[i][1];
  //cout<<"\nMissing Edges :\t"<<a<<","<<b<<endl;
  for(int j=0;j<n;j++) 
  {
   if(adj[a][j]==1 && j!=b)// && adj[b][j]==0)
   {
    //cout<<"Conn to a: "<<j<<endl;
    for(int k=0;k<n;k++)
    {
     fr=0;
     if(adj[b][k]==1 && k!=a)// && adj[a][k]==0)
     {
      //cout<<"Conn to b: "<<k<<endl;
      //cout<<"\n"<<j<<k;
      if(adj[j][k]==1)
      {
      truth=1;
      for(int o=0;o<up;o++)
      {
      if(a==c4[o][0])
      {
       if(b==c4[o][1])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][2])
       {
        if(j==c4[o][1])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][3])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
        if(j==c4[o][1])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
      }
      if(a==c4[o][1])
      {
       if(b==c4[o][0])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][2])
       {
        if(j==c4[o][0])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][3])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
        if(j==c4[o][0])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
      }
      if(a==c4[o][2])
      {
       if(b==c4[o][1])
       {
        if(j==c4[o][0])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][0])
       {
        if(j==c4[o][1])
        {
         if(k==c4[o][3])
         {fr=1;
         break;}
        }
        if(j==c4[o][3])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][3])
       {
        if(j==c4[o][0])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
        if(j==c4[o][1])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
       }
      }
      if(a==c4[o][3])
      {
       if(b==c4[o][1])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
        if(j==c4[o][0])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][2])
       {
        if(j==c4[o][1])
        {
         if(k==c4[o][0])
         {fr=1;
         break;}
        }
        if(j==c4[o][0])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
       }
       if(b==c4[o][0])
       {
        if(j==c4[o][2])
        {
         if(k==c4[o][1])
         {fr=1;
         break;}
        }
        if(j==c4[o][1])
        {
         if(k==c4[o][2])
         {fr=1;
         break;}
        }
       }
      }
      }
      if(fr==0)
      {
      c4[up][0]=a;
      c4[up][1]=b;
      c4[up][2]=j;
      c4[up++][3]=k;
      cout<<a<<","<<j<<","<<k<<","<<b<<endl;
      }
     }
    }
   }
  }
 }
}
}

//Determining miss edges(miss edge -> cycle)
void missedge_det()
{
 int a,b;
 h=0;
 int invalid=0;
 for(int i=0;i<t;i++)
 {
  invalid=0;
  a=edge[i][0];
  b=edge[i][1];
  for(int j=0;j<r;j++)
  {
    if( (bfsedge[j][0]==a && bfsedge[j][1]==b)||(bfsedge[j][0]==b && bfsedge[j][1]==a))
    {
     //cout<<"\n"<<a<<" "<<b;
     invalid=1;
    }
  }
  if(invalid==0)
  {
   missedge[h][0]=a;
   missedge[h++][1]=b;  
  } 
 }
 cout<<"\nMiss edge:\n";
 for(int p=0;p<h;p++)
  cout<<missedge[p][0]<<" "<<missedge[p][1]<<endl;
}

//check if there is a triangle
int check3()
{
 int a,b,found=0,q=0,fr=0;
 for(int i=0;i<z;i++)
 {
  a=crossedge[i][0];
  b=crossedge[i][1];
  for(int j=0;j<n;j++)
  {  
   fr=0;
   if(adj[a][j]==1 && adj[b][j]==1)
   {
    found=1;
    for(int o=0;o<q;o++)
    {
      if(a==c3[o][0])
      {
       if(b==c3[o][1])
       {
        if(j==c3[o][2]){
         fr=1;
         break;}
       }
       if(b==c3[o][2])
       {
        if(j==c3[o][1])
        { fr=1;break;}
       }
      }
      if(b==c3[o][0])
      {
       if(a==c3[o][1])
       {
        if(j==c3[o][2])
         {fr=1;break;}
       }
       if(a==c3[o][2])
       {
        if(j==c3[o][1])
         {fr=1;break;}
       }
      }
      if(j==c3[o][0])
      {
       if(b==c3[o][1])
       {
        if(a==c3[o][2])
         {fr=1;break;}
       }
       if(b==c3[o][2])
       {
        if(a==c3[o][1])
         {fr=1;break;}
       }
      }
     } 
     if(fr==0)
     {    
     c3[q][0]=a;
     c3[q][1]=b;
     c3[q++][2]=j;
     cout<<a<<","<<b<<","<<j<<endl;
     }
   }
  }
 }
 return found;
}

//Determining cross edges(cross edge -> odd cycle)
int crossedge_det()
{
 z=0;
 for(int i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
    if(l[i]==l[j])
    {
     if(adj[i][j]==1)
     {
      crossedge[z][0]=i;
      crossedge[z++][1]=j;
     }
   }
  }
 }
 return check3();
}

void bfs(int v)
{
 enqueue(v);
 int count=0,i;
 reach[v]=1;
 l[v]=0,r=0;
 cout<<endl;
 cout<<v<<endl;
 while(queueempty() != -1)
 {
  int cur=dequeue();
  for(i=0;i<n;i++)
  {
   cout<<"\t";
   if(adj[i][cur]==1 && reach[i]==0)
   {
    l[i]=l[cur]+1;
    cout<<i<<" "<<l[i];
    enqueue(i);
    bfsedge[r][0]=cur;
    bfsedge[r++][1]=i;
    reach[i]=1; 
    ++count;
   }
  }
  cout<<endl;
 }
 /*last=l[i-1];
 cout<<"\nlast"<<last<<endl;
 print();
 cout<<endl;*/
 cout<<"\nBFS EDGES:\n";
 for(int u=0;u<r;u++)
  cout<<bfsedge[u][0]<<","<<bfsedge[u][1]<<endl;
 flag=0,start;
 for(i=0;i<n;i++)
 {
  if(reach[i]==0)
  { 
   flag=1;
   break;
  }
 }
 int g=crossedge_det();
 if(g==0)
 {
 if(flag==1)
 {
  cout<<"\nDisconnected Graph...with vertex "<<i;
  bfs(i);
 }
 else
  cout<<"\n..C3 is not present";
 }
 else if(g==1)
  cout<<"\n...C3 is present";
}

int main(void)
{
 cout<<"\nEnter number of vertices: ";
 cin>>n;
 int i,a,b;
 srand(time(NULL));
 do
 {
 cout<<"\nEnter the edges:"; 
 cin>>a>>b;
 edge[t][0]=a;
 edge[t++][1]=b;
 adj[a][b]=1;
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
 bfs(0);
 //if(found==0)
  //cout<<"\n...C3 is not present...\n";
 missedge_det();
 check4();
 if(truth==1)
 {
  cout<<"\n...C4 is present...\n";
 }
 else if(truth==0)
 {
  cout<<"\n...C4 is not present...\n";
 }
}
