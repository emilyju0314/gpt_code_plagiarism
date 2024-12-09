#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
ll mod=1e6+3;
void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
ll ex(ll x,ll p){
	ll a=1;
	while(p){
		if(p%2) a=a*x%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
ll inv(ll x){
	return ex(x,mod-2);
}
void solve(int N,int K){
	ll dp[1001][2]={};
	dp[0][0]=1;
	rep(i,N) rep(j,2){
		rep1(k,K){
			if(i+k>N) break;
			add(dp[i+k][1-j],dp[i][j]);
		}
	}
	vector<int> ds;
	rep1(i,N) if(N%i==0) ds.pb(i);
	vector<ll> ans;
	rep(x,ds.size()){
		int d=ds[x];
		ll v=0;
		rep(i,K+1){
			if(d==i){
				if(N<=K) add(v,2);
				break;
			}
			add(v,2*i*dp[d-i][1]);
		}
		rep(y,x){
			if(d%ds[y]==0) add(v,-ans[y]*ds[y]);
		}
		v=v*inv(d)%mod;
		ans.pb(v);
	}
	ll ret=0;
	for(ll x:ans) add(ret,x);
	cout<<(ret+mod)%mod<<endl;
}
int main(){
	while(true){
		int N,K;
		cin>>N>>K;
		if(N==0) break;
		solve(N,K);
	}
}