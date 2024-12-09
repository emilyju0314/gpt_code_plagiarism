// solved few days ago
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int memo[300000]={0};

void init(){
	memo[0]=1;
	ll a = 1;
	for(int i=1;i<300000;i++){
		a*=i;
		a%=mod;
		memo[i]=a;
	}
}

ll mypow(ll a,ll b){
	if(b==1)return a;
	if(b==0)return 1;
	ll r = mypow(a,b/2);
	r = (r*r)%mod;
	if(b%2==1)r*=a;
	r%=mod;
	return r;
}

ll moddiv(ll a,ll b){
	return (a*mypow(b,mod-2))%mod;
}

ll fact(int n){
	ll a=1;
	for(int i=1;i<=n;i++){
		a*=i;
		a%=mod;
	}
	return a;
}

ll c(int n,int r){
	if(r<0)return 0;
	if(n<r)return 0;
	if(r==0)return 1;
	
	int a = memo[n];
	int b = memo[r];
	int c = memo[n-r];
	ll t = moddiv(a,b);
	t = moddiv(t,c);
	return t;
}

/*
int i=0;
ll route(int n,int m){
	i++;
	return c(n+m,min(n,m));
}

ll f(int n,int m,int k){
	if(k==0)return route(n,m);
	ll a=0;
	if(n>0)a += f(n-1,m,k);
	if(m>0)a += f(n,m-1,k);
	a += f(n+1,m,k-1);
	a += f(n,m+1,k-1);
	a%=mod;
	return a;
}*/

int main(){
	init();
	int n,m,k;
	cin >> n >> m >> k;
	ll ans=0;
	for(int i=0;i<=k;i++){
		int L = i;
		int D = k-i;
		ll x = c(n+L*2,L)-c(n+L*2,L-1);
		ll y = c(m+D*2,D)-c(m+D*2,D-1);
		ll comb = c(n+m+2*k,n+2*L);
		ll t = (x*y)%mod;
		t = (t*comb)%mod;
		ans = (ans+t)%mod;
	}
	while(ans<0)ans+=mod;
	cout << ans << endl;
}