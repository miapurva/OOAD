#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 3
int V,t=0;
int E;
int stack[SIZE][2];
int adj[SIZE][SIZE];
int top=-1;
int flag=0;
int a[SIZE];
int dfn[SIZE],low[SIZE],parent[SIZE], visited[SIZE];
int edge[SIZE][2];

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void push(int s[][2], int u, int v)
{
	if(top==(SIZE-1))
  		flag=0;
 	else
	{
		flag=1;
		top++;
		s[top][0]=u;
		s[top][1]=v;
	}
}
void display(int s[][2])
{
int i;
if(top==-1)
 {
cout<<"\n stack is empty";
 }
else
for(i=top;i>=0;--i)
 cout<<s[i][0]<<","<<s[i][1]<<endl;
}
int pop(int s[][2],int i)
{
	int pp; //popped element
	if(top==-1)
	{
		pp=0;
		flag=0;
		return 0;
	}
	else
	{
		/*flag=1;
		pp=s[top];
		--top;*/
		if(i==0)
	    {
		int yo1=s[top][0];
		int yo2=s[top][1];
		s[top][1]=-9;
        return yo2; 
        }
        else if(i==1)
        {
 		int yo1=s[top][0];
		int yo2=s[top][1];
		top--;
        return yo1;        
        } 
	}
}

/*void dfs(int vertex, int a[3][3], int disc[3], int low[3], int parent[3], int visited[3])
{
	static int time = 0;

	disc[vertex] = low[vertex] = time+1;
	time = time + 1;	
    visited[vertex]=1;
	int children=0;
	int k,l;

	for (int i=0; i<V;i++)
	{
		if(adj[vertex][i]==1)
		{
			if (visited[i]==0)
			{
				children=children+1;
				push(stack,u,v);
				parent[i]=vertex;
				dfs(i, adj, disc, low, visited, V);
				low[vertex]=min(low[vertex],low[i]);
				if(parent[vertex]==-1 && children>1)
				{
					k=pop(stack,0);
					l=pop(stack,1);
					while(k!=v && l!=u)
					{
						cout<<"\n Last element of stack:\t "<<k<<","<<l<<endl;
					}
					k=pop(stack,0);
					l=pop(stack,1);
					cout<<"\n Last element of stack:\t "<<k<<","<<l<<endl;	
				}
				if(parent[vertex]!=-1 && low[i]>=disc[vertex])
				{
					k=pop(stack,0);
					l=pop(stack,1);
					while(k!=(u||v) && l!=(u||v))
					{
						cout<<"\n Last element of stack:\t "<<k<<","<<l<<endl;	
					}
					k=pop(stack,0);
					l=pop(stack,1);
					cout<<"\n Last element of stack:\t "<<k<<","<<l<<endl;	
				}

			}
			else if(parent[vertex]!=i && disc[i]< low[vertex])
			{
				low[vertex]=disc[i];
				push(stack,u,v);
			}
		}
	}

}*/
void dfs(int u)
{
 // int t;
	int k,l;
	visited[u]=1;
	int child=0;
	dfn[u]=low[u]=++t;
	t=t+1;
 // cout<<"t="<<t<<endl;
	for(int j=0;j<V;j++)
  	{
    if(adj[u][j]==1)
    	{
       		int v=j;
       		if(visited[v]!=1)
       		{
	          	child++;
	          	push(stack,u,0);			//m
	          	push(stack,u,1);			//m
	          	parent[v]=u;
	          	dfs(v);
	          	low[u]=min(low[u],low[v]);
	          	if(parent[u]==0 && child>1)
	          	{
	  		     	a[u]=1;
	  		     	k=pop(stack,0);
					l=pop(stack,1);
	  		     	while(k!=(u|v) && l!=(u|v))
	  		     	{
	  		     		k=pop(stack,0);
	  		     		l=pop(stack,1);
	  		     		cout<<"\n 1 Last element of stack:\t "<<k<<","<<l<<endl;
	  		     	}
	          	}

	          	else if(parent[u]!=0 && low[v]>=dfn[u])
	            { 
	            	a[u]=1;
	            	k=pop(stack,0);
					l=pop(stack,1);
	            	while(k!=(u|v) && l!=(u|v))
	            	{
	            		k=pop(stack,0);
						l=pop(stack,1);
						cout<<"\n 2 Last element of stack:\t "<<k<<","<<l<<endl;
					}
	              // cout<<"u="<<u<<" ";
	    	    }
      	}
    else if (v != parent[u] && dfn[v]<low[u]) 
    {			//m
    
            low[u]  = min(low[u], dfn[v]);
    }
        
    } 
}

}

void bcc( int V1)
{
	for (int i = 0; i < V1; i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
		     
			while(top!=-1)
			{
				int k=pop(stack,0);
				int l=pop(stack,1);
				cout<<"\n 1 Last element of stack:\t "<<k<<","<<l<<endl;
			}
		}
	}
}/*
void bcc(int V)
{
  for(int i=0;i<V;i++)
  {
  	visited[i]=0;
  	parent[i]=-1;
  }
  dfs(0);
}*/


int main(void)
{
	cout<<"\n\t\t\t\t Welcome to Biconnected components(Complete Graph)"<<endl;
	cout<<"\nEnter number of vertices: ";

	cin>>V;
	int i,a,b;E=0;
	srand(time(NULL));
	do
	{
		cout<<"\nEnter the edges:"; 
		cin>>a>>b;
		//edge[E][0]=a;
		push(stack,a,b);
		//edge[E++][1]=b;
		adj[a][b]=1;
		adj[b][a]=adj[a][b];
		cout<<"\nEnter 1 to exit:";
		cin>>i;
		if(i==1)
 			break;
 	}while(1);
	for(int i=0;i<t;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
	for(int i=0;i<V;i++)
		adj[i][i]=-1;

	/*
	push(stack,1,2);
	push(stack,2,3);
	display(stack);
	pop(stack,0);
	pop(stack,1);
	display(stack);*/
	bcc(V);
	return(0);
}

