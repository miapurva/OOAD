#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 20
int V;
int visited[SIZE],dfn[SIZE],low[SIZE];
int adj[SIZE][SIZE];
int be[SIZE][SIZE]={};
int dfsm[SIZE][SIZE];

//Finding minimum
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}
/*
void dfs1(int cf)
{
	int i;
	visit[v]=1;
  
  for(i=1;i<=n;i++)
	{ 
	if(a[v][i]!=0 && visit[i]==0)
        {
			cout<<v<<" --> "<<i<<endl;
        	dfs1(i);
        }
   	}
}
*/

//BACK EDGE MATRIX
void backedge()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			be[i][j]=adj[i][j]-dfsm[i][j];
		}
	}
}
//DEPTH FIRST SEARCH
void dfs(int u)
{
	
	//int dfs[SIZE][SIZE];
  visited[u]=1;
  for(int i=0;i<V;i++)
  { 
	if(adj[u][i]==1 && visited[i]==0)
        {
        	//visited[i]=1;
         //ve[u][i]=1;
         //ve[i][u]=1;
         //push(stack,u,i);
        	dfsm[i][u]=1;
        	dfsm[u][i]=1;
		 cout<<u<<" --> "<<i<<endl;
			
         dfs(i);
		}
  }
  //cout<<"top ele :"<<stack[top][0]<<","<<stack[top][1]<<endl;
}

int book_detection()
{
	int flag=0;
	for (int i = 0; i < 6;	i++)
	{
		for (int j = 0; j < 6; j++)
		{
				if((((i!=0) || (j!=5)) && ((i!=4) || (j!=1))) && (((i!=5) || (j!=0)) && ((i!=1) || (j!=4))))
					{
						if(be[i][j]==1)
						{
							flag=1;
							break;
						}
					}
				else
				{
					if(be[i][j]==0)
					{
						flag=1;
						break;
					}
				}
		}
	}
	return(flag);
}

int main(void)
{
	cout<<"\n\t\t\t\t Welcome to Sweet: To detect a Book in a Graph"<<endl;
	cout<<"\nEnter number of vertices: ";
	cin>>V;
	int k,a,b;

	cout<<"Enter the Adjacency matrix:\n";
/*
	for(int i=0;i<V;i++)
	{
			cout<<"\t";
			for(int j=0;j<V;j++)
		{
			cout<<"\t";
			cin>>adj[i][j];
			
			
		}
		cout<<endl;
		//cout<<"\t";
	}
*/
 	do
	{
		cout<<"\nEnter the edges:"; 
		cin>>a>>b;
		//edge[E][0]=a;
		
		//edge[E++][1]=b;
		adj[a][b]=1;
		adj[b][a]=1;
		cout<<"\nEnter 1 to exit:";
		cin>>k;
		if(k==1)
 			break;
 	}while(1);
	/*for(int i=0;i<t;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<endl;*/
	for(int i=0;i<V;i++)
		adj[i][i]=0;
	cout<<"\nAdj Matrix : "<<endl;
	for(int i=0;i<V;i++)
    {
	  for(int j=0;j<V;j++)
		cout<<adj[i][j]<<" ";
	  cout<<endl;
    }


	dfs(0);		//for every node
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout<<" "<<dfsm[i][j];
		}
		cout<<endl;
	}

	cout<<endl<<"\t\t\t Welcome to BACKEDGE"<<endl;
	backedge();
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout<<" "<<be[i][j];
		}
		cout<<endl;

	}

	int flag;
	flag=book_detection();
	cout<<"Zenda: "<<flag<<endl;
	if(flag==0)
		cout<<"book detected"<<endl;
	else
		cout<<"I'm sorry"<<endl;


	return (0);
}