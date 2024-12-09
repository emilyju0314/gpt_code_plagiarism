#include<iostream>
#include<algorithm>
#include<queue>
#include<complex>
typedef long long ll;

using namespace std;
#define N 100010
ll n;
ll a[N],b[N],l[N],r[N];
ll sp,tp;
priority_queue<ll> S,s;
priority_queue<ll,vector<ll>,greater<ll> >T,t;
ll Sf(){
  return S.top()+sp;
}
ll Tf(){
  return T.top()+tp;
}
void Sp(ll x){
  S.push(x-sp);
}
void Tp(ll x){
  T.push(x-tp);
}
int main(){
    cin>>n;
    if(n>N)return 0;
    for(int i=0;i<n;i++)cin>>l[i]>>r[i];
    for(int i=1;i<n;i++){
      a[i]=l[i]-r[i-1];
      b[i]=r[i]-l[i-1];
    }
    ll ans=0; sp=tp=0;
    Sp(0); Tp(0);
    Sp(-1e17); Tp(1e17);
    for(int i=1;i<n;i++){
      sp-=b[i],tp-=a[i];
      ll s0=Sf();
      ll t0=Tf();
      if(s0<=0&&0<=t0){
	Sp(0); Tp(0);
      }
      if(0<s0){
	Sp(0); Sp(0);
	Tp(Sf());
	ans+=abs(Sf());
	S.pop();
      }
      if(t0<0){
	Tp(0); Tp(0);
	Sp(Tf());
	ans+=abs(Tf());
	T.pop();
      }
    }
    cout<<ans<<endl;
    return 0;
}
