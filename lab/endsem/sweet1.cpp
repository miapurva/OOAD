#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 20
int V;
int visited[SIZE],dfn[SIZE],low[SIZE];
int adj[SIZE][SIZE];
int be[SIZE][SIZE]={};
int dfsm[SIZE][SIZE];
int levelarray[5];

//Finding minimum
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

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
void dfs(int u,int level,int j)
{
	
	//int j=1;
	//int dfs[SIZE][SIZE];
  visited[u]=1;
  for(int i=0;i<V;i++)
  { 
	if(adj[u][i]==1 && visited[i]==0)
        {
        	dfsm[i][u]=1;
        	dfsm[u][i]=1;
        	levelarray[j]=i;
        	j++;
		 cout<<u<<" --> "<<i<<endl;
		if(level>=5)
		{
			return;
		}
         dfs(i,level+1,j);
		}
  }
}

int book_detection()
{
	int flag=0;
	for (int i = 0; i < 6;	i++)
	{
		for (int j = 0; j < 6; j++)
		{
				if((((i!=levelarray[0]) || (j!=levelarray[5])) && ((i!=levelarray[4]) || (j!=levelarray[1]))) && (((i!=levelarray[5]) || (j!=levelarray[0])) && ((i!=levelarray[1]) || (j!=levelarray[4]))))
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
	int zenda=0;

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

    for(int i=0;i<V;i++)
    {

	for(int k=0;k<V;k++)
	{
		visited[k]=0;
	}
	levelarray[0]=i;
		dfs(i,0,1);		//for every node
	// for (int i = 0; i < V; i++)
	// {
	// 	for (int j = 0; j < V; j++)
	// 	{
	// 		cout<<" "<<dfsm[i][j];
	// 	}
	// 	cout<<endl;
	// }
		//  cout<<"level"<<endl;
  // for(int f=0;f<6;f++)
  //  {
  //  	cout<<" "<<levelarray[f];
  //  }
  //  cout<<endl;
	backedge();
	int flag;
	flag=book_detection();
	//cout<<"Zenda: "<<flag<<endl;
	if(flag==0)
	{
		cout<<"book detected"<<endl;
		zenda=1;
		break;
	}
	}
	if(zenda!=1)
	{
		cout<<"I'm Sorry"<<endl;
	}
	return (0);
}