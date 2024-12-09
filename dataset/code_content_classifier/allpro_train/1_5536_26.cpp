#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,M,W,T;
map<string,int> mp;
string s[7];
ll v[7],p[7],l[7],x[7],y[7];
ll dp[100001];
vector<string> R[7];
vector<ll> Q[7];
ll a[(1<<7)],b[(1<<7)];

int main(){
  cin>>N>>M>>W>>T;
  for(int i=0;i<M;i++){
    cin>>s[i]>>v[i]>>p[i];
    assert(mp.count(s[i])==0);
    mp[s[i]]=i;
  }
  for(int i=0;i<N;i++){
    cin>>l[i]>>x[i]>>y[i];
    R[i].resize(l[i]);
    Q[i].resize(l[i]);
    for(int j=0;j<l[i];j++){
      cin>>R[i][j]>>Q[i][j];
      assert(mp.count(R[i][j])>0);
    }
  }
  for(int S=1;S<(1<<N);S++){
    vector<int> k;
    for(int i=0;i<N;i++)
      if(S>>i&1)k.push_back(i);
    ll mini=1e9;    
    do{
      ll cnt=0,px=0,py=0;
      for(int i=0;i<(int)k.size();i++){
        cnt+=abs(px-x[k[i]]);
        cnt+=abs(py-y[k[i]]);
        px=x[k[i]];
        py=y[k[i]];
      }
      cnt+=abs(x[k.back()]);
      cnt+=abs(y[k.back()]);
      mini=min(mini,cnt);
    }while(next_permutation(k.begin(),k.end()));
    
    if(mini>T)continue;
    memset(dp,0,sizeof(dp));
    vector<ll> c(M,0);
    for(int i=0;i<N;i++){
      if(S>>i&1){
        for(int j=0;j<l[i];j++){
          int id=mp[R[i][j]];
          c[id]=max(c[id],p[id]-Q[i][j]);
        }
      }
    }
    for(int i=0;i<M;i++){
      for(int j=v[i];j<=W;j++){
        dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
        a[S]=max(a[S],dp[j]);
      }
    }
    b[S]=mini;
  }
  ll ans=0;
  memset(dp,0,sizeof(dp));
  for(int i=1;i<(1<<N);i++){
    for(int j=b[i];j<=T;j++){
      dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
      ans=max(ans,dp[j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}