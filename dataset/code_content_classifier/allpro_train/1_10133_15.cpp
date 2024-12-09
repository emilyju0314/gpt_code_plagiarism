#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
//const long long mod = 1000000007LL;
//const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll mod = 1;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x% mod + mod) % mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
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

	// for prime mod
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};

mint dp[300][2000];

int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	ll n, k; scanf("%lld %lld %lld", &n, &k, &mod);
	dp[0][0] = 1;
	for (ll i = 0; i <= n * 2; i++) {
		for (ll S = 0; S < (1 << k) - 1; S++) {
			if (!(S >> (k - 1) & 1)) {
				ll nS = (S << 1) + 1;
				dp[i + 1][nS] += dp[i][S];
			}
			if (S != 0) {
				ll left = 0;
				for (ll j = 0; j < k; j++) {
					if (S >> j & 1) left = j;
				}
				ll nS = S - (1 << left);
				nS <<= 1;
				dp[i + 1][nS] += dp[i][S];
			}
		}
	}
	mint res = dp[n * 2][0];
	//横にばーってしてから横にばー
	if (n == k) res += 1;
	cout << res.x << endl;
	return 0;
}
