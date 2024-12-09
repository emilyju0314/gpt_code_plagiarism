#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  Int r,s,n;
  cin>>r>>s>>n;
  vector<Int> y(n),x(n);
  for(Int i=0;i<n;i++) cin>>y[i]>>x[i];

  vector<Int> v;
  for(Int i=0;i<n;i++){
    if(x[i]<=s) v.emplace_back((r-y[i]+1)+(s-x[i]+1));
    else v.emplace_back((r-y[i]+1)+(x[i]-s));
  }

  sort(v.begin(),v.end());

  
  Int ans=0;
  for(Int i=0;i<n;i++)
    ans=max(ans+1,v[i]);
  
  cout<<ans<<endl; 
  return 0;
}

