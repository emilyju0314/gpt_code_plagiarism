#include <bits/stdc++.h>
#define rmin 1e-9
using namespace std;

int main(){
  double t,n,m,v[100],r[100],e=-1,s,rr,rs;
  double E;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n>>m;
    s=0;
    rs=0;
    for(int j=0;j<m;j++) cin>>v[j]>>r[j],rs+=r[j];
    for(int j=0;j<m;j++){
      rr=0;
      while(r[j]>rmin) rr+=r[j],r[j]*=(1-rs);
      s+=rr*v[j];
    }
    e=max(e,s);
  }
  cin>>n>>m;
  s=0;
  rs=0;
  for(int i=0;i<m;i++) cin>>v[i]>>r[i],rs+=r[i];
  for(int i=0;i<m;i++){
    rr=0;
    while(r[i]>rmin) rr+=r[i],r[i]*=(1-rs);
    s+=v[i]*rr;
  }
  E=s;
  if(e>E) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}