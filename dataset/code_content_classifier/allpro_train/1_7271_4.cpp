#include <iostream>
#include <vector>
#include <utility>
#include <set>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
vector<llint> S[200005], T[200005];
set<pair<llint, llint> > s;

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		S[u].push_back(v);
		S[v].push_back(u);
	}
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
		if(u > v) swap(u, v);
		s.insert(make_pair(u, v));
	}
	
	llint ans = n*(n-1) % mod * modpow(4, mod-2) % mod;
	
	llint tmp = (n-2) * (n-1) % mod * modpow(8, mod-2);
	tmp *= 2, tmp %= mod;
	ans += mod - tmp, ans %= mod;
	
	tmp = (n-1)*(n-1) % mod;
	for(int i = 1; i <= n; i++){
		tmp += mod - (llint)S[i].size() * (llint)T[i].size() % mod;
		tmp %= mod;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < S[i].size(); j++){
			if(S[i][j] < i) continue;
			if(s.count(make_pair(i, S[i][j]))) tmp++, tmp %= mod;
		}
	}
	ans += tmp * modpow(16, mod-2) % mod;
	ans %= mod;
	cout << ans << endl;
	
	return 0;
}
