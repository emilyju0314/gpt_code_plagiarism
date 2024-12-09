#include<bits/stdc++.h>
using namespace std;
using Int = signed;
using ll = long long;
signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  Int n,m;
  cin>>n>>m;

  m++;
  vector<Int> a(m),b(m);
  for(Int i=0;i<m;i++) cin>>a[i];
  for(Int i=1;i<m;i++) cin>>b[i];

  vector<ll> hs;
  function<void(Int, Int)> predfs=[&](Int l,Int r){
    Int x=lower_bound(a.begin(),a.end(),r)-a.begin();
    if(a[x-1]<=l&&r<=a[x]) return;
    
    hs.emplace_back(((ll)l<<31)|r);
    Int m=(l+r)>>1;
    predfs(l,m);
    predfs(m,r);
  };

  predfs(0,(1<<n));
  sort(hs.begin(),hs.end());
  hs.erase(unique(hs.begin(),hs.end()),hs.end());
  map<ll, Int> idx;
  for(Int i=0;i<(Int)hs.size();i++) idx[hs[i]]=i;
  //cout<<hs.size()<<endl;
  
  vector<vector<Int> > dp(n+1,vector<Int>(hs.size(),-1));
  
  function<Int(Int, Int, Int, Int)> dfs=[&](Int l,Int r,Int d,Int k)->Int{
    //cout<<l<<" "<<r<<" "<<d<<" "<<k<<endl;
    Int x=lower_bound(a.begin(),a.end(),r)-a.begin();
    if(a[x-1]<=l&&r<=a[x]){
      Int v=b[x],tmp=0;
      tmp+=(k==v);
      tmp+=(r-l)>>(n-v+1);
      return tmp;
    }

    if(~dp[k][idx[((ll)l<<31)|r]]) return dp[k][idx[((ll)l<<31)|r]];
    Int &res=(dp[k][idx[((ll)l<<31)|r]]=0);
    
    Int m=(l+r)>>1;
    res=max(res,dfs(l,m,d+1,d)+dfs(m,r,d+1,k));
    res=max(res,dfs(l,m,d+1,k)+dfs(m,r,d+1,d));
    return res;
  };
  
  cout<<(1<<n)-dfs(0,1<<n,1,0)<<endl;
  return 0;
}

