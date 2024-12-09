#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow_mod(ll x,ll k,int MOD) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%MOD;
  	x=x*x%MOD;
  	k>>=1;
  }
  return ans;
}

inline int gcd(int x,int y) {
  return (x%y==0)?y:gcd(y,x%y);
}

inline ll lcm(int x,int y) {
  return (ll)x/gcd(x,y)*y;
}

int getphi(int n) {
  int s=n,t=n;
  for(int i=2;i*i<=t;i++)
    if (n%i==0) {
    	s=s/i*(i-1);
    	while (n%i==0) n/=i;
	}
  if (n>1) s=s/n*(n-1);
  return s;
}

void exgcd(ll a,ll b,ll &x,ll &y) {
  if (!b) {
  	x=1;y=0;
  }
  else {
  	exgcd(b,a%b,y,x);
  	y-=(a/b)*x;
  }
}

ll getinv(ll x,ll MOD) {
  ll t1,t2;
  exgcd(x,MOD,t1,t2);
  return (t1%MOD+MOD)%MOD;
}

ll excrt(int n,int m,ll x,ll y) {
  ll v=lcm(n,m);
  int d=gcd(n,m);
  n/=d;m/=d;
  ll ans=((y-x)/d%m+m)*getinv(n,m)%m;
  return (ans*n*d+x)%v;
}

ll solve(int a,int n) {
  if (n==1) return 1;
  int m=getphi(n);
  ll x=solve(a,gcd(n,m)),y=pow_mod(a,x,n);
  x%=m;
  ll ans=excrt(m,n,x,y);
  if (ans<=m) ans+=lcm(n,m);
  return ans;
}

int main() {
  int cases;
  scanf("%d",&cases);
  for(;cases;cases--) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	printf("%lld\n",solve(x,y));
  }
  return 0;
}