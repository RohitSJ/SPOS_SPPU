#include<iostream>
using namespace std;
int main()
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