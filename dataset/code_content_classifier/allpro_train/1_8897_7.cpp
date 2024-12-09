#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n; string s;
  cin>>n>>s;
  int l=0,r;
  r=count(s.begin()+1,s.end(),'E');
  int ans=r;
  rep(i,n-1){
    if(s[i]=='W'){l++;}
    if(s[i+1]=='E'){r--;}
    ans=min(ans, l+r);
  }
  cout<<ans;
}