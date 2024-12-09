#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& v) { if (sz(v)) writerArr(&v[0], sz(v)); else writer("\n"); }

const int NCK = 500;
double nck[NCK + 1][NCK + 1];
void calc_nck(){
	FOR(i, NCK){
		nck[i][0] = nck[i][i] = 1;
		for (int j = 1; j <= i; j++) {
			nck[i + 1][j] = (nck[i][j - 1] + nck[i][j]);
		}
	}
}

int n, m, l;
int pattern[3][7];
int ast;
double ans;

void check(const vector<vector<int>>& v){

	int x[60] = {};
	int mx = 0;
	FOR(i, sz(v)){
		FOR(j, sz(v[i])){
			x[mx++] = v[i][j];
		}
		mx++;
	}
	FOR(a, mx) FOR(b, mx) FOR(c, mx){
		int y[60] = {};
		FOR(i, 7){
			y[a + i] += pattern[0][i];
			y[b + i] += pattern[1][i];
			y[c + i] += pattern[2][i];
		}
		bool ok = true;
		FOR(i, 50) {
			if (x[i] < y[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			double add = 1;
			int z = sz(v) - 1;
			for (auto& v1 : v){
				z += sz(v1) - 1;
				for (auto i : v1) {
					add *= nck[n][i];
				}
			}
			if (m - z <= 0) return;
			add *= nck[m - z][sz(v)];
			ans += add;
			//if (add > 0) {
			//	for (auto& v1 : v) {
			//		printf("{");
			//		for (auto i : v1) {
			//			printf("%d ", i);
			//		}
			//		printf("} ");
			//	}
			//	printf("%f\n", add);
			//}
			return;
		}
	}
}

void dfs(vector<vector<int>>& v,int rem){
	if (rem == 0) {
		check(v);
		return;
	}
	if (sz(v.back()) != 0) {
		v.emplace_back();
		dfs(v, rem);
		v.pop_back();
	}
	FOR(i, rem){
		if (i + 1 > n) break;
		v.back().push_back(i + 1);
		dfs(v, rem - i - 1);
		v.back().pop_back();
	}
}


void solve(){
	vector<vector<int>> v(1);
	dfs(v, l);
	ans /= nck[n*m][l];
}

int main(){
	calc_nck();
	while (cin >> n >> m >> l, n) {
		ans = 0;
		ast = 0;
		memset(pattern, 0, sizeof(pattern));
		FOR(i, l){
			string s; cin >> s;
			if (s[0] != '*') pattern[s[0] - 'a'][sz(s) - 1]++;
			else ast++;
		}
		solve();
		printf("%.10lf\n", ans);
	}
}