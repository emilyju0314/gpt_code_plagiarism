# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 998244353;// 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max() / 2;
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourd; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<vector<int>>g;
vector<edge>edges;
vector<Pll>v;
map<Pll, Pll>ma;
set<LL>st;
LL h, w, n, m, k, t, s, p, q, last, cnt, sum, ans, a[210000], b[210000], dp[210000];
string str, ss;
bool f;
char c;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct LowLink {
	int n;
	vector<vector<int>> G;
	set<pair<int, int> > bridge;
	set<int> articulation;
	vector<int> ord, low;
	vector<bool> vis;
	LowLink() {}
	LowLink(int _n) :n(_n) {
		G.resize(_n);
		ord.resize(_n);
		low.resize(_n);
		vis.resize(_n);
	}
	LowLink(vector<vector<int>> &g) {
		G = g;
		n = G.size();
		ord.resize(G.size());
		low.resize(G.size());
		vis.resize(G.size());
	}
	void add_Edge(int x, int y) {
		G[x].push_back(y);
		G[y].push_back(x);
	}
	void build() {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) dfs(i, -1, k);
		}
	}

	void dfs(int v, int p, int &k)
	{
		vis[v] = true;

		ord[v] = k++;
		low[v] = ord[v];

		bool isArticulation = false;
		int ct = 0;

		for (int i = 0; i < G[v].size(); i++) {
			if (!vis[G[v][i]]) {
				ct++;
				dfs(G[v][i], v, k);
				low[v] = min(low[v], low[G[v][i]]);
				if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
				if (ord[v] < low[G[v][i]]) bridge.insert(make_pair(min(v, G[v][i]), max(v, G[v][i])));
			}
			else if (G[v][i] != p) {
				low[v] = min(low[v], ord[G[v][i]]);
			}
		}
		if (p == -1 && ct > 1) isArticulation = true;
		if (isArticulation) articulation.insert(v);
	}
	void print() {
		cout << "関節点の個数" << endl;
		cout << articulation.size() << "個" << endl;
		for (auto i = articulation.begin(); i != articulation.end(); i++)
			cout << *i << endl;
		cout << "橋の個数" << endl;
		cout << bridge.size() << "個" << endl;
		for (auto i = bridge.begin(); i != bridge.end(); i++)
			cout << i->first << "-" << i->second << endl;
	}
};
struct TwoEdgeConnectedComponent {
	int n;
	vector<vector<int>> g, tree;//木として見た時の辺が入っている
	vector<int> cmp;//木として見た時の頂点が入っている
	LowLink lnk;
	TwoEdgeConnectedComponent(int _n) {
		n = _n;
		cmp.assign(_n, -1);
		g.resize(_n);
		tree.resize(_n);
	}
	TwoEdgeConnectedComponent(const vector<vector<int>> &g) : g(g) {
		n = (int)g.size();
		cmp.assign(n, -1);
	}
	void add_Edge(int x, int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}
	void build() {
		lnk = LowLink(g);
		lnk.build();
		int k = 0;
		function<void(int, int)> dfs = [&](int u, int prev) {
			cmp[u] = k;
			for (auto v : g[u]) if (cmp[v] == -1 && lnk.bridge.count({ min(u, v), max(u, v) }) == 0) {
				dfs(v, u);
			}
		};
		for (int i = 0; i < n; i++) if (cmp[i] == -1) {
			dfs(i, -1);
			k++;
		}
		tree.resize(k);
		for (auto e : lnk.bridge) {
			tree[cmp[e.first]].push_back(cmp[e.second]);
			tree[cmp[e.second]].push_back(cmp[e.first]);
		}
	}
};
void dfs(int cur, int par) {
	vector<LL>ret;
	ret.push_back(0);
	ret.push_back(0);
	rep(i, g[cur].size()) {
		int v = g[cur][i];
		if (v == par)continue;
		dfs(v, cur);
		ret.push_back(dp[v]);
	}
	sort(ret.begin(), ret.end(), [](int x, int y) {return x > y; });
	if (ret.size() > 1)
		ans = max(ans, ret[0] + ret[1] + b[cur]);
		ans = max(ans, ret[0] + b[cur]);
	dp[cur] = ret[0] + b[cur];
}
int main() {
	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
	}
	g.resize(n);
	rep(i, m) {
		int x,y;
		cin >> x>>y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	TwoEdgeConnectedComponent tec(g);
	tec.build();
	rep(i, tec.cmp.size()) {
		b[tec.cmp[i]] += a[i];
	}
	g = tec.tree;
	dfs(0,-1);
	cout << ans << endl;
	return 0;
}
