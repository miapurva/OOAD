//IN A GROUP OF 7 PEOPLE THERE EXISTS 3 MUTUAL FRIENDS OR 3 MUTUAL ENEMIES

#include<iostream>
using namespace std;

long int count=0;

class Group
  {
     public:
       long int Relation[7][7];
       void ways(int i);
       void store(int a[]);
       void check();
       void allCheck();
       long int pow(int x,int y);
  };

//CHECKS IF THERE EXISTS 3 MUTUAL FRIENDS OR 3 MUTUAL ENEMIES
void Group::check()
  {
    int flag=0;
    for(int i=0;i<7;i++)
      for(int j=0;j<7;j++)
        for(int k=j+1;k<21;k++)
          if((Relation[i][j]==Relation[i][k])&&(Relation[i][j]==Relation[j][k]))
            flag=1;
    if(flag==1)
      count++;
  }

//STORES THE ELEMENTS OF ADJACENCY MATRIX
void Group::store(int a[])
  {
    int k=0;
    for(int i=0;i<7;i++)
      for(int j=0;j<7;j++)
        if(i<j)
          Relation[i][j]=a[k++];
    for(int i=0;i<7;i++)
      for(int j=0;j<7;j++)
        {
          if(i>j)
            Relation[i][j]=Relation[j][i];
          if(i==j)
            Relation[i][j]=9;
        }
    check();
}

//FINDS ALL 2^21 DIFFERENT WAYS
void Group::ways(int i)
  { 
    static int a[21];
    if(i==21)
      cout<<a;
    else if(i>=0 && i<21)
      {
        for(int k=0;k<=1;k++)
          {
            a[i]=k;
            ways(i+1);
          }
      }
  }

//POWER FUNCTON FOR 2 ELEMENTS
long int Group::pow(int x,int y)
  {
    long int prd=1;
    for(int i=1;i<=y;i++)
      prd=prd*x;
    return prd;
  }

//CHECKS IF THE CONDITION IS TRUE FOR ALL POSSIBLITIES
void Group::allCheck()
  {
    if(count==(pow(2,21)))
      cout<<"\nSuccess";
    else
      {
        cout<<"\nCount: "<<count;
        cout<<"\nFailure";
      }
    cout<<endl;
  }
  
int main(void)
  {
    Group g;
    g.ways(0);
    g.allCheck();
    return 0;
  }
