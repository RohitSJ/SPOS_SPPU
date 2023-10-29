#include<iostream>
using namespace std;
 

 
int firstfit()
{
int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
cout<<"Enter no. of blocks: ";
cin>>bno;
cout<<"\nEnter size of each block: ";
for(i = 0; i < bno; i++)
cin>>bsize[i];
 
cout<<"\nEnter no. of processes: ";
cin>>pno;
cout<<"\nEnter size of each process: ";
for(i = 0; i < pno; i++)
cin>>psize[i];
for(i = 0; i < pno; i++)         //allocation as per first fit
for(j = 0; j < bno; j++)
if(flags[j] == 0 && bsize[j] >= psize[i])
{
allocation[j] = i;
flags[j] = 1;
break;
}
//display allocation details
cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
for(i = 0; i < bno; i++)
{
cout<<"\n"<< i+1<<"\t\t"<<bsize[i]<<"\t\t";
if(flags[i] == 1)
cout<<allocation[i]+1<<"\t\t\t"<<psize[allocation[i]];
else
cout<<"Not allocated";
}
return 0;
}


int bestfit()


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

int worstfit()
{
    int bno,pno,bsize[20],psize[20];
    cout<<" Enter the number of blocks: "; 
    cin>>bno;
    cout<<" Enter the size of "<<bno<<" blocks: ";
    for(int i=0;i<bno;i++) 
    cin>>bsize[i];

    cout<<" Enter the number of processes: "; 
    cin>>pno;
    cout<<" Enter the size of "<<pno<<" processes: ";
    for(int i=0;i<pno;i++) 
    cin>>psize[i];

      for(int i=0;i<pno;i++)
      {
        int max = bsize[0];

           int pos = 0;
           for(int j=0;j<bno;j++)

            if(max < bsize[j]) {
                 max = bsize[j]; 
                 pos = j;
                } 
            if(max >= psize[i])
            {

                cout<<"\nProcess "<<i+1<<" is allocated to block "<<pos+1;

                bsize[pos] = bsize[pos]-psize[i];
            }
            else{
                cout<<"\nProcess "<<i+1<<" can't be allocated";\
            }
        }
    return 0;
}


int main()
{

    int option = 0;

    while(option != 4){
  
        //cout << "Available Options:\n";
        cout << "1.FirstFit\n";
        cout << "2.BestFit\n";
        cout << "3.WorstFit\n";
       
        cout<<"Enter your choice: ";
        cin >> option;

        switch(option){
            case 1:
                firstfit();
                break;

            case 2:
                bestfit();
                break;

            case 3:
            worstfit();
            break;


            case 4:
                cout<<"\n***** You have exited *****\n";
                break;

            default:
                cout<<"Enter valid option!\n";
                break;
        }
    
    }
    return 0;
}