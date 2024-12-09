#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
#define F first
#define S second
const ll MOD=1000000007;
const ll E=1e18;

set<vector<ll>> ans;
multiset<ll> cost;
set<ll> point;
ll n;
ll l,r;

void dfs(ll d){
  if(d==n){
    ll L=l;
    auto I=point.begin(); ++I;
    vector<ll> ret;
    for(;I!=point.end();++I){
      ret.push_back((*I)-L);
      L=*I;
    }
    ans.insert(ret);
    return;
  }
  auto I=cost.end(); I--;
  ll dist=*I;
  ll w=dist+l;
  vector<ll> used;
  bool j=true;
  for(auto I=point.begin();I!=point.end();++I){
    auto T=cost.find(abs(*I-w));
    if(T!=cost.end()){
      used.push_back(abs(*I-w));
      cost.erase(T);
    }
    else{
      j=false;
      break;
    }
  }
  if(j && point.count(w)==0){
    point.insert(w);
    dfs(d+1);
    point.erase(w);
  }
  for(auto &I:used){cost.insert(I);}
  used.clear();
  
  w=r-dist;
  j=true;
  for(auto I=point.begin();I!=point.end();++I){
    auto T=cost.find(abs(*I-w));
    if(T!=cost.end()){
      used.push_back(abs(*I-w));
      cost.erase(T);
    }
    else{
      j=false;
      break;
    }
  }
  if(j && point.count(w)==0){
    point.insert(w);
    dfs(d+1);
    point.erase(w);
  }
  for(auto &I:used){cost.insert(I);}
}




int main(){
  while(cin>>n){
    if(n==0){break;}
    //for(auto &I:ans){I.clear();}
    ans.clear();
    cost.clear();
    point.clear();
    l=0; cin>>r;
    for(int i=1;i<n*(n-1)/2;i++){
      ll d;
      cin>>d;
      cost.insert(d);
    }
    point.insert(l);
    point.insert(r);
    dfs(2);
    for(auto &I:ans){
      for(int i=0;i+1<n;i++){cout<<I[i]<<(i+2==n?"\n":" ");}
    }
    cout<<"-----"<<endl;
  }

  return 0;
}

