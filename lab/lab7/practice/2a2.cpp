#include <iostream>
#include <cstdlib>
using namespace std;

int adj[100][100],n,visit[100],parent[100],dfn[100],low[100],a[100],t=0,Lvalue[100];

int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

void apu(int u)
{
 // int t;
    visit[u]=1;
    int child=0;
    dfn[u]=low[u]=++t;
 
    for(int j=0;j<n;j++)
    {
        if(adj[u][j]==1)
        {
            int v=j;
            if(visit[v]!=1)
            {
                child++;
                parent[v]=u;
                apu(v);
                low[u]=min(low[u],low[v]);
                if(parent[u]==-1 && child>1)
                    a[u]=1;
                else if(parent[u]!=-1 && low[v]>=dfn[u])
                { 
                    a[u]=1;
              // cout<<"u="<<u<<" ";
                }
            }
            else if (v != parent[u])
            low[u]  = min(low[u], dfn[v]);
        
        } 
    }

}


void Bridges()
{
    //for the bridges
    cout << "\nThe bridges are: " << endl;
    for (int i = 0; i < n ; i++) 
    {	//cout<<"hi1";
        for (int j = 0; j < n ; j++)
         {
         	//cout<<"hi2";
            if(adj[i][j] == 1)
            {
            	cout<<"hi1";
            	//if(visit[j] < visit[i])
               // {
                	cout<<"hi2";
                	if(low[i] > visit[j])
                	{
                		cout << "(" << j << "," << i << ")" << endl;
                	}
					
				//}
            }
        }
    }
}

int main()
{
    int x=1,p,q;
    cout<<"Enter the number of vertices :\t";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
            adj[j][i]=0;
        }
    }
    for(int i=0;i<n;i++)
        adj[i][i]=-1;

    while(x==1)
    {
        cout<<"Enter the edges"<<endl;
        cin>>p>>q;
        adj[p][q]=1;
        adj[q][p]=1;
        cout<<"Enter 1 to continue:\t";
        cin>>x;
    }
    for(int i=0;i<n;i++)
        parent[i]=-1;
    for(int i=0;i<n;i++)
        visit[i]=0;
    for(int i=0;i<n;i++)
        a[i]=0;

    for (int i = 0; i < n; i++)
    {  
        if (visit[i] ==0)
            apu(i);
     // cout<<"i"<<i<<endl;
    }
        cout<<"\nAP : \n"; 
    // Now ap[] contains articulation points, print them
    for (int i = 0; i<n; i++)
    {
        if (a[i] ==1)
            cout << i <<"\n";   
    }
        cout<<endl;

        Bridges();
        cout<<endl;

    return 0;
}
