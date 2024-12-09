#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  while(cin>>n>>m){
    if(n==0 && m==0) return 0;
  
  vector<int> A(n+1);
  rep(i,n) cin>>A[i];
  A[n]=0;
  
  vector<int> B;
  B.push_back(0);
  rep(i,n+1){
    rep(j,n+1){
      if(A[i]+A[j]<=m) B.push_back(A[i]+A[j]);
    }
  }
  sort(ALL(B));
  B.erase(unique(ALL(B)),B.end());

  ll ans=0;
  rep(i,B.size()){
    auto itr=upper_bound(ALL(B),m-B[i])-B.begin();
    ll tmp=B[i]+B[itr-1];
    ans=max(ans,tmp);
  }
  
  cout<<ans<<endl;
  }
  
}
