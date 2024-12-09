#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

struct union_find {
	vector<int> v;
	int k;
	union_find(int n) : v(n, -1), k(0) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
			k++;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	for (;;) {
		int n, m; cin >> n >> m;
		if (n == 0) break;
		vector<int> s(m), t(m), c(m);
		for (int i = 0; i < m; i++) {
			cin >> s[i] >> t[i] >> c[i];
			s[i]--; t[i]--;
		}
		for (int C = 1; C <= 1000; C++) {
			union_find ufs(n), ufe(n), ufg(n);
			for (int i = 0; i < m; i++) {
				if (c[i] <= C) ufs.unite(s[i], t[i]);
				if (c[i] >= C) ufg.unite(s[i], t[i]);
			}
			if (ufs.k >= n / 2 && ufg.k >= n / 2 - 1) {
				cout << C << endl;
				break;
			}
		}
	}
}