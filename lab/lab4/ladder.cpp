//ALL POSSIBLE WAYS FOR THE MONKEY TO CLIMB THE STEP 'n'

#include<iostream>
using namespace std;

class Ladder
  {
    int m_count,m_n;//PRIVATE VARIABLE
    public:
        
        int m_size;
        Ladder();//CONSTRUCTOR FUNCTION
        void PrintArray(int a[],int l);
        void PosWays(int m_size,int i);
        void TotalWays();
      
  };

//USED TO INITIALIZE CLASS MEMBER VARIABLES
//THIS FUNCTION IS INVOKED WHEN THE OBJECT OF THIS CLASS IS CREATED
Ladder::Ladder()
  {
    m_count=0;
    cout<<endl<<"Enter the LadderLength : ";
    cin>>m_size;
    m_n=m_size;
  }

//PRINTS THE ELEMENTS OF ARRAY 'a'
void Ladder::PrintArray(int a[],int l)
  {
    for(int j=0;j<l;j++)
      cout<<a[j]<<"  ";
      cout<<endl;
  }

//STORES THE ALL POSSIBLE WAYS TO CLIMB LADDER
void Ladder::PosWays(int m_size,int i)
  {
    static int a[100];
    if(m_size==0)
      {
        m_count++;
        PrintArray(a,i);
      }
    else if(m_size>0)
      {
        for(int k=1;k<=2;k++)
          {
            a[i]=k; 
            PosWays(m_size-k,i+1);
          }
      }
  }

//PRINTS THE TOTAL NUMBER OF WAYS TO CLIMB A LADDER
void Ladder::TotalWays()
  {
    cout<<"THE TOTAL NUMBER OF WAYS TO CLIMB A LADDER "<<m_n<<" is: "<<m_count<<endl;
  }

//MAIN FUNCTION
int main(void)
  {
    Ladder ladder1;
    ladder1.PosWays(ladder1.m_size,0);
    ladder1.TotalWays();
    return 0;
  }


