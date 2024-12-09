#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--){
    double r,b,d;
    cin>>r>>b>>d;
    if(d==0){
        if(r==b)cout<<"yes"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
      double x=abs(r-b);
      if(r<ceil(x/d)||b<ceil(x/d))cout<<"NO"<<endl;
      else cout<<"YES"<<endl;
    }
   }
    return 0;
}