#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
  ll n;
  cin>>n;
  ll d[2*n];
  for(int i=0;i<2*n;i++){
    cin>>d[i];
  }
  sort(d,d+2*n);
  reverse(d,d+2*n);
  vector<ll> v;
  for(ll i=1;i<2*n;i++){
    if(i%2==1&&d[i]!=d[i-1]){
      cout<<"NO\n";
      return;
    }
    else if(i%2==1&&d[i]==d[i-1]){
      v.push_back(d[i]);
    }
  }
  for(int i=1;i<n;i++){
    if(v[i]==v[i-1]){
      cout<<"NO\n";
      return;
    }
  }

  // for(int i=0;i<n;i++){
  //   cout<<v[i]<<" ";
  // }
  // cout<<"\n";
  ll curr = 0;
  ll prev = 0;
  for(int i=0;i<n;i++){
    if(v[i]-curr<=0){
      cout<<"NO\n";
      return;
    }
    if((v[i]-curr)%(2*(n-i))!=0){
      cout<<"NO\n";
      return;
    }
    else{
      prev = (v[i]-curr)/(2*(n-i));
      curr+=2*prev;
    }
  }
  cout<<"YES\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
