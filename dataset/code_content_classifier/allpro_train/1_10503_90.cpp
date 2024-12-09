#include<bits/stdc++.h>
using namespace std;
    int square (int n)
    {
        int x = sqrt(n);
        return (x*x==n);
    }
int main()
{
   int t ;
   cin>>t;
   while(t--)
   {
       long long n;
       cin>>n;
       if(n%2==0 && square(n/2))
       {
           cout<<"YES"<<endl;
       }
       else if(n%4==0 && square(n/4))
       {
           cout<<"YES"<<endl;
       }
       else
       {
           cout<<"NO"<<endl;
       }
   }
   
   

    return 0;
}