#include<iostream>
using namespace std;
 
int main()
{
  int bno,pno,temp,lowest=9999, a1[20],a2[20],b[20],p[20];

  cout<<"Enter number of blocks ";
  cin>>bno;

    cout<<"Enter size of each block"<<endl;
  for(int i=1;i<=bno;i++)
    cin>>b[i];
  cout<<"Enter number of processes ";
  cin>>pno;
  
  cout<<"\nEnter size of each process."<<endl;
  for(int i=1;i<=pno;i++)
    cin>>p[i];

  
  for(int i=1;i<=pno;i++)
  {
    for(int j=1;j<=bno;j++)
    {
      if(a1[j]!=1)
      {
        temp=b[j]-p[i];
        if(temp>=0)
          if(lowest>temp)
          {
            a2[i]=j;
            lowest=temp;
          }
      }
    }
    a1[a2[i]]=1;
    lowest=10000;
  }
  
  cout<<endl<<"Process number\tProcess size\tBlock number\tBlock size";
  for(int i=1;(i<=pno and a2[i]!=0);i++)
  {
    cout<<endl<<i<<"\t\t"<<p[i]<<"\t\t"<<a2[i]<<"\t\t"<<b[a2[i]];
  }
  return 0;
}