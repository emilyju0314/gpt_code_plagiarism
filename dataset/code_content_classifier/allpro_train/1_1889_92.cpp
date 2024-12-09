#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B,ans=0;
  cin>>N>>A>>B;
  while(N--){
    int t;
    cin>>t;
    if(t<A || B<=t)ans++;
  }
  cout<<ans<<endl;
}