#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10
int V,t=0;
int E;
int stack[SIZE][2];
int adj[SIZE][SIZE];
int top=-1,tr;
int flag=0,ur;
int a[SIZE],arp[SIZE],ve[SIZE][SIZE];
int dfn[SIZE],low[SIZE],parent[SIZE], visited[SIZE],couart[100][2];
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

/*void dfs1(int v)
{

 //push(v);
 visited[v]=1;
 //printf("%d\n",v);
  
 int i=;
 do
 {
   
  {if(adj[v][i]==1 && visited[i]==0)
    {
    	push(stack,i,v); //child,parent
        
     cout<<v<<","<<i<<endl;
     visited[i]=1;
 }
  else 
  {
   pop(stack,0);
   pop(stack,1);
  }
 }
  cout<<endl;
}while(top!=-1);
}*/

void dfs1(int v)
{
  int i;
  visited[v]=1;
  for(i=0;i<V;i++)
  { 
	if(adj[v][i]==1 && (ve[i][v]==0))
        {
         ve[v][i]=1;
         ve[i][v]=1;
         push(stack,v,i);
		 cout<<v<<","<<i<<endl;
         dfs1(i);
		}
  }
  cout<<"top ele :"<<stack[top][0]<<","<<stack[top][1]<<endl;
}

void apu(int u)
{
 // int t;
  visited[u]=1;
  int child=0;
  dfn[u]=low[u]=++t;
 // cout<<"t="<<t<<endl;
 for(int j=0;j<V;j++)
  {
    if(adj[u][j]==1)
     {
       int v=j;
       if(visited[v]!=1)
        {
          child++;
          parent[v]=u;
          apu(v);
          low[u]=min(low[u],low[v]);
          if(parent[u]==-1 && child>1)
             a[u]=1;
          else if(parent[u]!=-1 && low[v]>=dfn[u])
            { a[u]=1;
              // cout<<"u="<<u<<" ";
            }
        }
      else if (v != parent[u])
            low[u]  = min(low[u], dfn[v]);
        
     } 
  }

}

void sort(int couart[100][2])
{  
	int temp1,temp;

	for(int e=0;e<ur;e++)
	  {
     
	  	for(int w=e+1;w<ur;w++)
	  	{
	  		if(couart[e][1]<couart[w][1])
              { temp=couart[e][1];
              	temp1=couart[e][0];
                couart[e][1]=couart[w][1];
                couart[e][0]=couart[w][0];
                couart[w][1]=temp;
                couart[w][0]=temp1;
                
              }	

	  	}
	  }
}
void bcc()
{
 sort(couart);
 cout<<"in bcc"<<endl;
 for(int i=0;i<ur;i++)
 	cout<<couart[i][0]<<" "<<couart[i][1]<<endl;
 for(int i=0;i<ur;i++)
    		{  
    		  //count=0; 
    			cout<<"poped: \t"<<endl;
    			cout<<stack[top][0]<<","<<stack[top][1]<<endl;
    		  for(int w=0;w<=top;w++)
    		  {  //cout<<"hi"<<endl;
    		  	//j=top;
    			if(couart[i][0]==stack[w][0])
    				{  //cout<<"hi1"<<endl;
    					//couart[ur][0]=arp[i];
    					//couart[ur][1]=count;
    			       //cout<<endl;
    					break;
    				}
    		 	//cout<<"popped elements"<<endl;	
    				
    			int a=pop(stack,0);
    			int b=pop(stack,1);
    			//cout<<b<<","<<a<<",";	
    			cout<<b<<","<<a<<endl;
    			//count=count+1;
    		    }
    		   
    		   int c=pop(stack,0);
    		   int d=pop(stack,1); 
    		   //cout<<d<<","<<c<<",";
    		   cout<<d<<","<<c<<endl; 
    		    //ur++;
    		}


 }

		


int main(void)
{
	cout<<"\n\t\t\t\t Welcome to Biconnected components(Complete Graph)"<<endl;
	cout<<"\nEnter number of vertices: ";
	cin>>V;
	int i,ar,b;E=0;
	srand(time(NULL));
	do
	{
		cout<<"\nEnter the edges:"; 
		cin>>ar>>b;
		//edge[E][0]=a;
		push(stack,ar,b);
		//edge[E++][1]=b;
		adj[ar][b]=1;
		adj[b][ar]=1;
		cout<<"\nEnter 1 to exit:";
		cin>>i;
		if(i==1)
 			break;
 	}while(1);
	/*for(int i=0;i<t;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<endl;*/
	for(int i=0;i<V;i++)
		adj[i][i]=-1;
	cout<<"\nAdj Matrix : "<<endl;
	for(int i=0;i<V;i++)
    {
	  for(int j=0;j<V;j++)
		cout<<adj[i][j]<<" ";
	  cout<<endl;
	}
	for(int i=0;i<V;i++)
	  ve[i][i]=-1;
    for(int i=0;i<V;i++)
    {
	  for(int j=0;j<V;j++)
		  ve[i][j]=0;
	}
	for(int i=0;i<V;i++)
  {
  	//cout<<"\nhi\n";
  	visited[i]=0;
  	parent[i]=-1;
  }
	dfs1(0);
	for(int i=0;i<V;i++)
  {
  	//cout<<"\nhi\n";
  	visited[i]=0;
  	parent[i]=-1;
  }
	for(int i=0;i<V;i++)
    	apu(i);
    cout<<"\nAP : "<<endl;
    tr=0;
    for(int i=0;i<V;i++)
      if(a[i]==1)
      	{arp[tr++]=i;
    	cout<<i<<endl;   }
	//bcc();
    	cout<<"tr :"<<tr<<endl;
    	ur=0;
int count;
    	for(int i=0;i<tr;i++)
    		{  
    		  count=0; 
    		  cout<<"top in main :" <<stack[top][0]<<" ,"<<stack[top][1]<<endl;
    		  for(int w=top;w>-1;w--)
    		  	{  cout<<"hi"<<endl;
    		  	//j=top;
    			if(arp[i]==stack[w][0])
    				{  cout<<"hi1"<<endl;
    					couart[ur][0]=arp[i];
    					couart[ur][1]=count;
    					break;
    				}
    			count=count+1;
    		    }
    		    ur++;
    		}
    		cout<<"ur :"<<ur<<endl;
    		for(int i=0;i<ur;i++)
    		  cout<<couart[i][0]<<" "<<couart[i][1]<<endl;	
    		  	bcc();
	return(0);
}

