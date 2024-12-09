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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

//const int max_n = 1 << 22;
//modint fact[max_n], factinv[max_n];
//void init_f() {
//	fact[0] = modint(1);
//	for (int i = 0; i < max_n - 1; i++) {
//		fact[i + 1] = fact[i] * modint(i + 1);
//	}
//	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
//	for (int i = max_n - 2; i >= 0; i--) {
//		factinv[i] = factinv[i + 1] * modint(i + 1);
//	}
//}
//modint comb(int a, int b) {
//	if (a < 0 || b < 0 || a < b)return 0;
//	return fact[a] * factinv[b] * factinv[a - b];
//}

typedef long double Data;
typedef vector<Data> Array;
typedef vector<Array> mat;

pair<mat, vector<int>> LUPDecomposition(mat a) {
	int n = a.size();
	vector<int> perm(n);
	iota(begin(perm), end(perm), 0);
	rep(i, n) {
		int pivot = i;
		for (int j = i + 1; j < n; ++j)
			if (abs(a[j][i]) > abs(a[pivot][i]))pivot = j;
		swap(a[pivot], a[i]);
		swap(perm[pivot], perm[i]);
		for (int j = i + 1; j < n; ++j) {
			a[j][i] /= a[i][i];
			for (int k = i + 1; k < n; ++k) {
				a[j][k] = fma(-a[i][k], a[j][i], a[j][k]);
			}
		}
	}
	return make_pair(a, perm);
}
Array LUPBackSubstitution(mat& LU, vector<int>& perm, Array a) {
	int n = LU.size();
	Array tmp(n);
	rep(i, n)tmp[i] = a[perm[i]];
	swap(tmp, a);
	rep(i, n) {
		rep(j, i) {
			a[i] = fma(-a[j], LU[i][j], a[i]);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			a[i] = fma(-a[j], LU[i][j], a[i]);
		}
		a[i] /= LU[i][i];
	}
	return a;
}
Array calc(mat A, Array b) {
	pair<mat, vector<int>> p = LUPDecomposition(A);
	return LUPBackSubstitution(p.first, p.second, b);
}

struct edge {
	int to, cost;
};
int n, s, t;
void solve() {
	s--; t--;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<vector<edge>> G(n),GG(n);
	vector<int> dist(n, mod);
	rep(i, n) {
		rep(j, n) {
			int c; cin >> c;
			if (c > 0) {
				G[i].push_back({ j,c });
			}
		}
	}
	dist[t] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ 0,t });
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int id = p.second;
		if (p.first > dist[id])continue;
		for (edge e : G[id]) {
			int nd = dist[id] + e.cost;
			if (dist[e.to] > nd) {
				dist[e.to] = nd;
				q.push({ nd,e.to });
			}
		}
	}
	if (dist[s] == mod) {
		cout << "impossible" << endl; return;
	}
	rep(i, n) {
		for (edge e : G[i]) {
			if (dist[e.to] + e.cost == dist[i]) {
				GG[i].push_back(e);
			}
		}
	}
	mat A(n);
	Array b(n);
	rep(i, n) {
		A[i].resize(n, 0);
		if (dist[i] == mod)continue;
		if (i == t) {
			A[i][i] = 1; continue;
		}
		A[i][i] -= 1;
		if (a[i]) {
			int p = GG[i].size();
			for (edge e : GG[i]) {
				A[i][e.to] += 1 / (ld)p;
				b[i] -= e.cost / (ld)p;
			}
		}
		else {
			int p = G[i].size();
			for (edge e : G[i]) {
				A[i][e.to] += 1 / (ld)p;
				b[i] -= e.cost / (ld)p;
			}
		}
	}
	/*rep(i, n){
		rep(j, n) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	rep(i, n)cout << b[i] << endl;*/
	Array z = calc(A, b);
	ld ans = z[s];
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	//init_f();
	//int t; cin >> t; rep(i, t)solve();
	while (cin >> n >> s >> t, n | s | t) {
		solve();
	}
	stop
		return 0;
}

