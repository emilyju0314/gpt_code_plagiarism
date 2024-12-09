#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,p,q;
  cin>>n>>p>>q;
  vector<Int> c(n);
  for(Int i=0;i<n;i++) cin>>c[i];
  vector<Int> d(n);
  
  Int res=0;
  for(Int i=0;i<n;i++){
    d[i]=(q+i)*p;
    res+=d[i];
  }
  
  Int ans=res;
  
  vector<Int> v(n);
  for(Int i=0;i<n;i++)
    v[i]=c[i]-d[i]+2*p*(i-n);     
  
  sort(v.rbegin(),v.rend());
  vector<Int> s(n+1,0);
  for(Int i=0;i<n;i++) s[i+1]=s[i]+v[i];

  for(Int i=1;i<=n;i++){
    res+=2*p*i;
    Int tmp=res+s[i];
    chmax(ans,tmp);
  }
  
  cout<<ans<<endl;
  return 0;
}

