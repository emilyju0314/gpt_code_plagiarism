#include <bits/stdc++.h>
using namespace std;

int main() {
   int r,g,b,n,a,t,x;
  cin>>r>>g>>b>>n;
  
  int ans=0;
  
  for(a=0;a <= n/r;a++){
    for(t=0;t <= n-a*r;t++){
      if((n-r*a-g*t)%b == 0 && n-r*a-g*t >= 0){
        
        ans++;}
    }
  }
  cout<<ans<<endl;
}
