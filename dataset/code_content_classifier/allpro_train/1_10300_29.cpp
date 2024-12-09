#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;};


signed main(){
  Int n;
  string s;
  
  while(cin>>n>>s,n){
    using ull = unsigned long long;
    ull m=0;

    auto calc=[](char c){if(isdigit(c)) return c-'0';return c-'A'+10;};
  
    for(Int i=0;i<(Int)s.size();i++){
      m=m*n+calc(s[i]);
    }

    using P = pair<Int, Int>;
    vector<P> vp;
    Int k=n;
    for(Int i=2;i<=50;i++){
      if(k%i) continue;
      vp.emplace_back(i,0);
      while(k%i==0) k/=i,vp.back().second++;
    }
  
    ull ans=m;

    for(auto p:vp){
      ull k=p.first;
      ull res=0;
      while(k<=m){
	res+=m/k;
	if(k>=ULLONG_MAX/p.first-1) break;
	k*=p.first;
      }
      chmin(ans,res/p.second);
    }
  
    cout<<ans<<endl;
  }
  return 0;
}


