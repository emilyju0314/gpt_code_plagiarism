#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

#define mkp make_pair
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))

ll dp[5005][5005];

void add(ll &a,ll b){
  a=(a+b)%MOD;
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(N);
  rep(i,N) cin>>A[i];

  vector<pair<int,int>> v;
  int ma=0;
  int now=0;
  int sx=0,sy=0;
  while(now<N){
    int mi=A[now],mit=now;
    for(int j=now;j<N;j++){
      if(mi>A[j]){
        mi=A[j];
        mit=j;
      }
    }

    bool ok=true;
    for(int j=now;j+1<mit;j++){
      if(A[j]>A[j+1]) ok=false;
    }
    if(ok==false){
      cout<<0<<endl;
      return 0;
    }

    if(mi<ma){
      sx++;
      sy+=mit-now;
      now=mit+1;
    }else{
      if(now>0) v.push_back(mkp(sx,sy));
      sx=1;
      sy=mit-now;
      now=mit+1;
    }

    for(int j=0;j<=mit;j++) ma=max(ma,A[j]);
  }
  v.push_back(mkp(sx,sy));

  dp[0][0]=1;
  for(int i=0;i<v.size();i++){
    int x=v[i].first;
    int y=v[i].second;
    for(int j=0;j<=N;j++){
      if(j+x<=N) add(dp[i+1][j+x],dp[i][j]);
      if(j+y<=N) add(dp[i+1][j+y],dp[i][j]);
    }
  }

  ll ans=0;
  for(int j=0;j<=N;j++){
    if(j<=M&&N-j<=M) add(ans,dp[v.size()][j]);
  }
  cout<<ans<<endl;

  return 0;
}

