#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint& a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint& a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const  mint& a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint& a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint& a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint& a) const {
		mint res(*this);
		return res *= a;
	}

	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint& a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint& a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream& os, const mint& m) {
		os << m.x;
		return os;
	}
};

mint pw(mint a, ll b) {
	if (b == 0) { return 1; }
	mint ret = pw(a, b >> 1);
	ret *= ret;
	if (b & 1) { ret *= a; }
	return ret;
}

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

//////////////////////////////////////

int main() {
	ll N, M;
	cin >> N >> M;

	ll L = max(N, M);
	vvvll mat(L + 1);

	mat[0].assign(1, vll(1, 0));

	repn(i, L) {
		ll K = 1 << i;

		mat[i].assign(K, vll(K, 0));

		rep(x, K)rep(y, K) {
			ll t = mat[i - 1][x % (K / 2)][y % (K / 2)];
			if (x >= K / 2 && y >= K / 2) { mat[i][x][y] = 1 - t; }
			else { mat[i][x][y] = t; }
		}

		//rep(x, K) {
			//rep(y, K)cout << mat[i][x][y];
			//cout << endl;
		//}
	}

	vvll ans(1 << L, vll(1 << L, 0));
	repn(x, (1 << L) - 1)repn(y, (1 << L) - 1) {
		ans[x][y] = (mat[L][x - 1][y] + mat[L][x][y - 1] + mat[L][x - 1][y - 1]  +mat[L][x][y]) % 2;
	}

	repn(x, (1 << N) - 1) {
		repn(y, (1 << M) - 1)cout << ans[x][y];
		cout << endl;
	}
}