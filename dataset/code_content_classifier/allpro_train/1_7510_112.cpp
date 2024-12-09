#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;cin>>s;
  ll ans=0;
  ll now=0;
  for(ll i=0;i<s.size();i++){
    if(s[i]=='B')continue;
    ans+=i-now;
    now++;
  }
  cout<<ans;
}