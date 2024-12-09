#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll x,ll y,ll z){
  ll A=x*x*x+y*y*y;
  return (A<=z*z*z) ? A:0;
}

int main(){
  ll z;
  while(cin>>z,z){

    ll mx=0;
    for(int i=1;i<2000;i++)
      for(int j=1;j<2000;j++)mx=max(mx,calc(i,j,z));
    cout<<z*z*z-mx<<endl;
  }
  return 0;
}