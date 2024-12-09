#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll N,M,K;
ll T;
ll fast,slow,mid;
 
vector<ll> t;
typedef pair<ll,ll> P;
 
priority_queue< P > Q;

ll search(ll x,ll v){
  if(x>T)return 0;
  return (T-x)/v+1;
}

void solve(){
  ll ans=0;
  vector<ll> v;
  if( (N-1)*fast <= T )ans++;
  
  for(int i=0;i+1<(int)t.size();i++){
    ll left=t[i];
    ll right=t[i+1];
    ll lx=(left-1)*fast;
    ll Fi=search(lx,slow);
    ans+=min(left+Fi,right)-left;
    //cout<<left<<' '<<left+Fi<<endl;
    
    for(int j=0;j<K-M;j++){
      ll Se=search(lx+Fi*mid,slow);
      ll first=left+Fi;
      ll second=left+Fi+Se;
      first=min(first,right);
      second=min(second,right);
      v.push_back(max(0LL,second-first));
      Fi+=Se;
    }
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(int i=0;i<K-M;i++){
    ans+=v[i];
  }
  cout<<ans-1<<endl;
}
 
int main(){
  cin>>N>>M>>K;
  cin>>slow>>fast>>mid;
  cin>>T;
  t.resize(M);
  for(int i=0;i<M;i++)cin>>t[i];
  solve();
  return 0;
}