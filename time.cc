#include <iostream>
using namespace std;


int main()
{

int  N=0, sum=0, n=0; //C1
   cout<<"how many numbers ? \n";    //C2
   cin >>n; //C3

   for(int k=0; k<n; k++) //C4 * (n+1)
    {  
        cout<<"enter an integer "<<endl; //C5* n
        cin>>N;   //C6 * n
        if(N%2==1) //C7 * n
        sum = sum+N; //C8 * n
     }
      cout<<"sum of odd numbers "<<sum<<endl; // C9

    return 0;
   
   }

   //runtime
   // C1 + C2 + C3 + C4(n+1) + C9 + n(C5+C6+C7+C8)