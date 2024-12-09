#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#define __float128 long double
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int N = 1010;
int dp[N][N][2];

int rec(int odd, int even, int parity){
	if (odd + even == 2) return parity;

	int &res = dp[odd][even][parity];
	if (res + 1) return res;

	res = 0;
	if (odd >= 2) res |= !rec(odd - 2, even + 1, parity);
	if (odd&&even) res |= !rec(odd, even - 1, !parity);
	if (even >= 2) res |= !rec(odd, even - 1, !parity);

	return res;
}

struct UnionFind{
	vector<int> par, sz;
	UnionFind(int n){
		par = sz = vector<int>(n);
		for (int i = 0; i < n; ++i) par[i] = i, sz[i] = 1;
	}
	int find(int x){
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y){
		x = find(x), y = find(y);
		if (x == y) return;
		par[x] = y;
		sz[y] += sz[x];
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	int size(int x){
		return sz[find(x)];
	}
};

int main(){

	int n;
	cin >> n;
	UnionFind uf(n);

	vector<string> v(n);
	rep(i, n) cin >> v[i];

	rep(i, n) rep(j, n){
		char c = v[i][j];
		if (c == 'Y') uf.unite(i, j);
	}
	
	vector<int> edge(n);
	rep(i, n) rep(j, i){
		char c = v[i][j];
		if (c == 'Y') --edge[uf.find(i)];
	}

	set<int> st;

	int odd = 0, even = 0, parity = 0;
	rep(i, n){
		int x = uf.find(i);
		if (st.count(x)) continue;
		st.insert(x);
		int sz = uf.size(x);
		if (sz & 1) ++odd;
		else ++even;

		int cnt = sz*(sz - 1) / 2;
		if((cnt - edge[x])&1) parity ^= 1;
	}

	MEMSET(dp, -1);
	cout << (rec(odd, even, parity) ? "Taro" : "Hanako") << endl;

	return 0;
}