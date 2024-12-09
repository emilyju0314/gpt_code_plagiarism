#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

bool isp[100000];
vector<ll> p;
void init() {
	fill(isp+2, isp + 100000, true);
	Rep(i, 2, 100000) {
		if (!isp[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < 100000; j += i) {
			isp[j] = false;
		}
	}
}
ll mod_pow(ll x, int n, ll m) {
	x %= m;
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%m;
		x = x * x%m; n >>= 1;
	}
	return ret;
}
ll Euler_t(int x) {
	ll ret = 1;
	rep(i, p.size()) {
		if (x%p[i] == 0) {
			ret *= (p[i] - 1);
			x /= p[i];
			while (x%p[i] == 0) {
				x /= p[i]; ret *= p[i];
			}
		}
	}
	if (x > 1)ret *= (x - 1);
	return ret;
}
vector<int> divis(int x) {
	vector<int> ret;
	int k = sqrt(x);
	rep1(i, k) {
		if (x%i == 0) {
			ret.push_back(i);
			ret.push_back(x / i);
		}
	}
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}
ll gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y) {
		ll r = x % y; x = y; y = r;
	}
	return x;
}
ll lcm(ll x, ll y) {
	ll g = gcd(x, y);
	return x / g * y;
}
int main() {
	init();
	int n; cin >> n; int cop = n;
	if (n == 2) {
		cout << 1 << endl; return 0;
	}
	if (n % 2 == 0) {
		cout << -1 << endl; return 0;
	}
	bool f = true;
	vector<ll> u;
	rep(i, p.size()) {
		if (n % (p[i] * p[i]) == 0) {
			f = false; break;
		}
		if (n%p[i]==0) {
			u.push_back(p[i]); n /= p[i];
		}
	}
	if (n > 1)u.push_back(n);
	if (!f) {
		cout << -1 << endl;
	}
	else {
		ll ans = 1;
		rep(i, u.size()) {
			int r = cop / u[i];
			int z = Euler_t(u[i] - 1);
			vector<int> d = divis(z);
			int chk = -1;
			rep(j, d.size()) {
				ll s = mod_pow(r, d[j], (u[i] - 1));
				if (s == 1) {
					chk = d[j];
					break;
				}
			}
			if (chk < 0) {
				cout << -1 << endl; return 0;
			}
			ans = lcm(ans, chk);
		}
		cout << ans << endl;
	}
	//stop
	return 0;
}

