#include<iostream>
#include<cstdlib>
using namespace std;

int dist[100],visit[100],adj[100][100],n,e,shset[100];

int mindist()
{
  int min=3594754;
  int index;
  for(int j=0;j<n;j++)
   {
     if(shset[j]==0 && dist[j]<=min)
        {
         min=dist[j];
         index=j;
        }
    }
  return index;  
}

void dij(int s)
{
  dist[s]=0;
  for(int j=0;j<n;j++)
   {
     int u=mindist();
     shset[u]=1;
    for(int k=0;k<n;k++)
     {
       if(!shset[k] && adj[u][k] && dist[u]!=3594754 && (dist[u]+adj[u][k]<dist[k]))
       dist[k]=dist[u]+adj[u][k];
   }
   }


}


int main()
{
 int x=1,p,q,w;
  int i=0,po;
  cout<<"enter no of vertices :";
  cin>>n;
  cout<<"\nEnter source vertex : ";
  cin>>po;
  for(int j=0;j<n;j++)
   {
     for(int k=0;k<n;k++)
      {
       adj[j][k]=0;
       }
    }
  for(int j=0;j<n;j++)
    dist[j]=0;
  while(x==1)
   {
    cout<<"enter edges : "<<endl;
    cin>>p>>q;
    cout<<"enter edge "<<p<<q<<" weight :";
    cin>>w;
    adj[p][q]=w;
    adj[q][p]=w;
    //s[i][0]=p;
   // s[i][1]=q;
   
    //s[i][2]=w;
    cout<<"enter 1 to conti"<<endl;
    cin>>x;
    i++;
   }
  e=i;
  for(int j=0;j<n;j++)
    adj[j][j]=0;
  for(int j=0;j<n;j++)
    {shset[j]=0;
      dist[j]=3594754;}
    dij(po);
  for(int j=0;j<n;j++)
    cout<<j<<" "<<dist[j]<<endl;

return 0;
}
