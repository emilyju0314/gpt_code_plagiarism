#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

template <unsigned int MOD>
struct ModInt {
	using uint = unsigned int;
	using ull = unsigned long long;
	using M = ModInt;

	uint v;

	ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
	M& set_norm(uint _v) { //[0, MOD * 2)->[0, MOD)
		v = (_v < MOD) ? _v : _v - MOD;
		return *this;
	}

	explicit operator bool() const { return v != 0; }
	M operator+(const M& a) const { return M().set_norm(v + a.v); }
	M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
	M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
	M operator/(const M& a) const { return *this * a.inv(); }
	M& operator+=(const M& a) { return *this = *this + a; }
	M& operator-=(const M& a) { return *this = *this - a; }
	M& operator*=(const M& a) { return *this = *this * a; }
	M& operator/=(const M& a) { return *this = *this / a; }
	M operator-() const { return M() - *this; }
	M& operator++(int) { return *this = *this + 1; }
	M& operator--(int) { return *this = *this - 1; }

	M pow(ll n) const {
		if (n < 0) return inv().pow(-n);
		M x = *this, res = 1;
		while (n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}

	M inv() const {
		ll a = v, b = MOD, p = 1, q = 0, t;
		while (b != 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(p -= t * q, q);
		}
		return M(p);
	}

	bool operator==(const M& a) const { return v == a.v; }
	bool operator!=(const M& a) const { return v != a.v; }
	friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
	static int get_mod() { return MOD; }	
};

using Mint = ModInt<998244353>;

Mint dp[2][510][512];
Mint pf[2][510][512];

int main() {
	int N, X;
	cin >> N >> X;

	dp[0][0][0] = 1;
	int c = 0, f = 1;

	for (int i = 1; i <= N; ++i) {
		for (int k = 0; k < 512; ++k) {
			for (int j = 0; j <= X; ++j) {
				pf[c][j][k] = dp[c][j][k];
				if (j) {
					pf[c][j][k] += pf[c][j-1][k];
				}
			}
		} 

		for (int j = 0; j <= X; ++j) {
			for (int k = 0; k < 512; ++k) {
				int pre = k ^ j;
				dp[f][j][k] = pf[c][j][pre];
			}
		}
		swap(c, f);
	}

	Mint ans = 0;
	for (int i = 0; i <= X; ++i) {
		ans += dp[c][i][X];
	}
	cout << ans << endl;

	return 0;
}
