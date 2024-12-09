#include <algorithm>
#include<stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include<stack>
#include <queue>
#include<map>
#include <set>
#include<math.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Rep(i,n) for(ll i=1;i<=n;++i)
#define loop(i,m,n) for(ll i=m;i<n;++i)
#define ggr getchar(); getchar();return 0;
#define pie 3.141592653589793238462643383279
#define elif else if
#define P pair<ll,ll>
#define prique priority_queue<ll>
const int mod = 1000000007;
const int mod2 = 998244353;
int bin(int bina) {
	int ans = 0;
	for (int i = 0; bina > 0; i++)
	{
		ans = ans + (bina % 2) * pow(10, i);
		bina = bina / 2;
	}
	return ans;
}
bool prime(int n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % mod;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
long nCr(int n, int r) {
	int ans = 1;
	for (ll i = n; i > n - r; --i) {
		ans = ans * i;
	}
	for (ll i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}
struct union_find {
	int par[200010], size_[200010];
	void init(int x) {
		rep(i, x) { par[i] = i; size_[i] = 1; }
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		if (size_[x] < size_[y]) {
			par[x] = y;
			size_[y] += size_[x];
		}
		else {
			par[y] = x;
			size_[x] += size_[y];
		}
	}
};

signed main() {
	cout << "square1001" << endl;
}
