//BINARY SEARCH TREE

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
  struct node *parent;
}*root=NULL,*temp;

//COUNT
int c=1;
int count(struct node *t)
{
 if(t==NULL)
	return 0;
 else
 {
	 c += count(t->lchild);
	 c += count(t->rchild);
	 return c;
 }
}

//INSERT
void insert(struct node *r,struct node *t)
{
 if(r==NULL)
	return;
 else if(t->data<=r->data)
 {insert(r->lchild,t);
  if(r->lchild==NULL)
    {
	  r->lchild=t;
      t->parent=r;
	}
 }
 else if(t->data>r->data)
 {insert(r->rchild,t);
  if(r->rchild==NULL)
    { 
      r->rchild=t;
	  t->parent=r;
	}
  }
}
//CREATE NODE
void create(int t)
{
 struct node *temp=new(struct node);
 temp->lchild=NULL;
 temp->rchild=NULL;
 temp->data=t;
 //temp->parent=NULL;

 if(root==NULL)
 {root=temp;
 root->parent=NULL;}
 else 
  {
   insert(root,temp);  
  }
} 
void inorder(struct node *n)
{
if(n==NULL)
		return;
	else
	{
		inorder(n->lchild);
		cout<<n->data<<"\n";
		inorder(n->rchild);
	}
}

 void findmax(struct node *n)
 {
	if(n->rchild == NULL)
		 cout<<"\n"<<n->data;
	 else
		 findmax(n->rchild);
		
 }
int main(void)
 {
 srand(time(NULL));
  int i,data;
  struct node *r;
  cout<<"\n\t\t\tBINARY SEARCH TREE\n";
  do{
   int x;
   cout<<"\n1 to insert\n\t2 to display\n";
   cin>>x;
   switch(x)
   {
	case 1:cout<<"\nEnter data to insert:";
	       data=rand()%100;
	       cout<<data<<"\n";
		   create(data);
           break;
    case 2://cout<<"\MAX:\t";
    	inorder(root);
           findmax(root);
           break;
    
    case 3:exit(0);
    default:cout<<"\nEnter valid number:\t";
   }
   cout<<"\nEnter(1/0):\t";
   cin>>i;
  }while(i==1);
  
 }
