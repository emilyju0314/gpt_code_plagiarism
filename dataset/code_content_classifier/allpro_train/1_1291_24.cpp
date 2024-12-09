#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1<<18];
int rec(int k,int d){
  //cout<<k<<" "<<d<<endl;
  if(d==n){
    return a[k];
  }
  int x=rec(k*2,d+1),y=rec(k*2+1,d+1);
  if(x==y) return x;
  if(x<y)  return y-x;
  if(x>y)  return x-y;
}
signed main(){
  cin>>n;
  for(int i=0;i<(1<<n);i++) cin>>a[i];
  cout<<rec(0,0)<<endl;
  return 0;
}
