#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int s,t,d;
  cin>>s>>t>>d;
  int w[d];
  for(int i=0;i<d;i++) cin>>w[i];
  int a[d+1];
  a[0]=0;
  for(int i=0;i<d;i++) a[i+1]=a[i]+w[i];
  int k=*min_element(a,a+d+1);
  if(s+k>t&&a[d]>=0){
    cout<<-1<<endl;
    return 0;
  }
  for(int i=0;i<=d;i++){
    if(s+a[i]<=t) {
      cout<<i<<endl;
      return 0;
    }
  }
  int l=0,r=1000000;
  while(l+1<r){
    int m=(l+r)/2;
    //cout<<m<<":"<<s+a[d]*m<<" "<<t<<endl;
    int x=0;
    for(int i=0;i<=d;i++){
      if(s+a[d]*m+a[i]<=t) {
	x=1;
	break;
      }
    }
    if(x) r=m;
    else l=m;
  }
  //cout<<r<<endl;
  int ans=r*d;
  for(int i=0;i<=d;i++){
    if(s+a[d]*r+a[i]<=t) break;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}

