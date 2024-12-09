#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;

int mod;

struct mint {
	int val;
	mint() { val = 0; }
	mint(const lint& v) {
		val = (-mod <= v && v < mod) ? v : v % mod;
		if (val < 0) val += mod;
	}

	friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
	friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
	friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

	mint operator-() const { return mint(-val); }
	mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
	mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
	mint& operator*=(const mint& m) { val = (lint)val*m.val%mod; return *this; }
	friend mint ipow(mint a, lint p) {
		mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }

	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
	operator int64_t() const {return val; }
};

mint ez(int n, int k){
	vector<mint> dp(n + 2);
	dp[0] = mint(1);
	for(int i=1; i<=n+1; i++){
		for(int j=1; j<=k+1 && j<=i; j++){
			dp[i] += dp[i - j];
		}
	}
	return dp[n + 1];
}

vector<int> v;
int dp[155][155][155], n, k;

mint f(int pos, int l, int r){
	if(r >= k + 2) return mint(0);
	if(pos == sz(v)) return mint(1);
	if(~dp[pos][l][r]) return dp[pos][l][r];
	mint ret = f(pos + 1, 0, 0);
	if(v[pos] & 1){
		ret += f(pos + 1, l + 1, 0);
	}
	if(v[pos] & 2){
		ret += f(pos + 1, 0, r ? (r + 1) : 0);
	}
	if(v[pos] == 3){
		ret += f(pos + 1, l + 1, max(l + 2, r + 1));
	}
	return dp[pos][l][r] = (lint)ret;
}

int main(){
	cin >> n >> k >> mod;
	if(k % 2 == 0){
		cout << ez((n + 1) / 2, k / 2) * ez(n / 2, k / 2) << endl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=n+n; i+=2){
		if(i - k > n) break;
		int msk = 0;
		if(i <= n) msk |= 1;
		if(i - k >= 1) msk |= 2;
		v.push_back(msk);
	}
	cout << f(0, 0, 0) << endl;
}

