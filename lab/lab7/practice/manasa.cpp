#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int n,a,b,top=-1,number=1;
int graph[100][100];
int dfn[100]={0};
int l_value[100]={0};
int stack[100][2];
void push(int x,int y)
{
	stack[++top][0]=x;
	stack[top][1]=y;
}
void pop()
{
	top--;
}
int minimums(int x,int y)
{
	if(y<x)
		return(y);
	else return(x);
}
void display()
{
	cout<<endl;
	cout<<endl;
	for(int i=0;i<top+1 ;i++)
	{
		cout<<" "<<stack[i][0]<<" "<<stack[i][1]<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void biconnected_components(int u,int v)
{
	dfn[u]=number;
	l_value[u]=number;
	number++;
	for(int i=1;i<n+1;i++)
	{
		if(graph[u][i]==1)
		{
			if(v!=i && dfn[i]<dfn[u])
			{
				push(u,i);
			}
			if(dfn[i]==0 && top!=-1)
			{
				biconnected_components(i,u);
				l_value[u]=minimums(l_value[u],l_value[i]);
				if(l_value[i]>=dfn[u] && top!=-1)
				{
					cout<<"\n new biconnected component:"<<endl;
					do
					{
						a=stack[top][0];
						b=stack[top][1];
						pop();
						if(a!=b)
							cout<<" "<<a<<"- "<<b<<endl;

					}while(((a!=u || b!=i) && (a!=i || b!=u)) && top!=-1 && a!=0 && b!=0);
				}
			}
			else if(i!=v)
				l_value[u]=minimums(l_value[u],dfn[i]);
		}
	}
}
int main()
{
	int i,j;
	cout<<"enter the size of the graph: "<<endl;
	cin>>n;
	cout<<"enter the graph elements: "<<endl;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			cin>>graph[i][j];
		}
		cout<<endl;
	}
	cout<<"\nthe entered graph is :"<<endl;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			cout<<"  "<<graph[i][j];
		}
		cout<<endl;
	}
	srand(time(NULL));
	///int v=1+rand()%n;
	int v=1;
	biconnected_components(v,0);
	return(0);
}