#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll cal(ll r,ll c){
  ll L=0,R=1e15,m;
  while(L<R){
    m=(L+R)/2;
    if(r*m/100<c)L=m+1;
    else R=m;
  }
  return L;
}

int main(){
  ll m,rd,rr,cd,cr;
  cin>>m>>rd>>rr>>cd>>cr;
  m-=cal(rd,cd)+cal(rr,cr);
  if(m<0)m=-1;
  cout<<m<<endl;
  return 0;
}

