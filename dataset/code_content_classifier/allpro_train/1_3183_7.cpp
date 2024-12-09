#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 6000
int n;
vector<int> g[N];
bool used[N];
int t[N], w[N];
ll inv[N], fact[N], ifact[N];
ll dp[N], dp2[N];
 
void init_fact(ll n = N){
    inv[1] = 1;
    for(int i = 2; i < n; i++) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < n; i++){
		fact[i] = (fact[i-1]*i)%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}

void dfs(int u){
	used[u] = true;
	t[u] = 1;
	for(auto v: g[u]){
		if(used[v]) continue;
		dfs(v);
		t[u] += t[v];
		chmax(w[u], t[v]);
	}
	chmax(w[u], n-t[u]);
}

int main(){
	init_fact();
	cin>>n;
	rep(i, n-1){
		int x, y;
		cin>>x>>y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	int wx = 0;
	rep(i, n) if(w[i]<w[wx]) wx = i;
	rep(i, n){
		if(w[i]==w[wx] && i!=wx){
			cerr<<"b"<<endl;
			cout<<fact[n/2]*fact[n/2]%mod<<endl;
			return 0;
		}
	}
	mset(used, 0);
	dfs(wx);
	dp[0] = 1;
	for(auto v: g[wx]){
		memcpy(dp2, dp, sizeof(dp));
		ll s = t[v], r = 1;
		for(ll i = 1; i <= s; i++){
			r = r*(s-i+1)%mod;
			ll r2 = fact[s]*ifact[i]%mod*ifact[s-i]%mod;
			for(ll j = n; j >= i; j--){
				(dp[j]+=dp2[j-i]*r%mod*r2%mod)%=mod;
			}
		}
	}
	ll res = 0;
	rep(i, n){
		(res+=dp[i]*fact[n-i]%mod*(i%2?-1:1))%=mod;
	}
	(res+=mod)%=mod;
	cout<<res<<endl;
	/*
	cerr<<"start debug"<<endl;
	cerr<<"c "<<wx<<endl;
	rep(i, n) cerr<<dp[i]<<endl;
	cerr<<"s "<<g[wx].size()<<endl;
	for(auto v: g[wx]) cerr<<t[v]<<endl;
	*/
	return 0;
}
