#include <iostream>
#include <cstdlib>
using namespace std;

int adj[100][100],visit[100],parent[100],dfn[100],low[100],a[100], stack[100][2];
int V,E=0,t=0,c;

int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

//PUSH
void push(int s[100][2], int u, int v)
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

//DISPLAY
void display(int s[100][2])
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

//POP
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

void bridges(int u, int v)
{
    for (int i = 0; i < E; i++)
    {
        int u=i;
        adj[u][v]=adj[v][u]=0;
        for (int j = 0; j < V; j++)
        {
            visit[j]=0;           
        }
            push(stack,u,i);
            cout<<u<<", "<<i<<endl;
            //push(stack,v,i);
            //cout<<v<<", "<<i<<endl;
            visit[u][i]=1;
            //check=0;
            while(top=-1)
            {
                x=pop(stack,0);
                y=pop(stack,1);
                if((x==u && y==v) || (x==v && y==u))
                {
                    check=1;
                    break;
                }
                //delete the queue somehow
                for (int j = 0; i < V; j++)
                {
                    if(adj[x][j]==true && visit[j]==1)
                    {
                        push(stack,x,0);
                        push(stack,j,1);
                        visit[j]=1;
                    }
                }
            }
            adj[u][v]=adj[v][u]=1;
            if(check==0)
                isbridge[i]=1;

    }
}

/*void bridge1(int a,int v)
{
    low[v]=dist[v]=t+1;
    visit[v]=1;
    for(int i = 0; i < V ; i++)
    {
        if(a[v][i]==1 && visited[i]==1)
            cout<<"There exists an edge"<< <<" which acts as a bridge\n"<<endl;

        else
        {
            //cout<<"There's no edge between"<< <<" & "<< <<endl;
            break;
        }
    }
}*/

void bridge2()
{
    low[v]=dfn[v]=t+1;
    visit[v]=1;
    for(int i=0;i<n;i++)
    {
        if(adj[v][i])
        {
            if(!visit[i])
            {
                parent[i]=v;
                bridge2(i);
                low[v]=min(low[v],low[i]);
                if(low[i]>dfn[v])
                {
                    cout<<v<<" "<<i<<endl;
                }
            }
            else if(parent[v]!=i)
                low[v]=min(low[v],dfn[i]);
        }
    }
}


void apu(int u)
{
 // int t;
    visit[u]=1;
    int child=0;
    dfn[u]=low[u]=++t;
 
    for(int j=0;j<V;j++)
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

int main()
{
    int x=1,p,q;
    cout<<"Enter the number of vertices :\t";
    cin>V;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            adj[i][j]=0;
            adj[j][i]=0;

        }
    }
    for(int i=0;i<V;i++)
        adj[i][i]=-1;

    while(x==1)
    {
        cout<<"Enter the edges"<<endl;
        cin>>p>>q;
        adj[p][q]=1;
        adj[q][p]=1;
        E++;
        cout<<"Enter 1 to continue:\t";
        cin>>x;
    }
    cout<<"Total no. of edges: \t"<<E<<endl;

    for(int i=0;i<V;i++)
        parent[i]=-1;
    for(int i=0;i<V;i++)
        visit[i]=0;
    for(int i=0;i<V;i++)
        a[i]=0;

    for (int i = 0; i < V; i++)
    {  
        if (visit[i] ==0)
            apu(i);
     // cout<<"i"<<i<<endl;
    }
        cout<<"\nAP : \n"; 
    // Now ap[] contains articulation points, print them
    for (int i = 0; i<V; i++)
    {
        if (a[i] ==1)
            cout << i <<"\n";   
    }
    for (int i = 0; i<V; i++)
    {
        bridge1(a,i);
    }
    
        cout<<endl;
    return 0;
}
