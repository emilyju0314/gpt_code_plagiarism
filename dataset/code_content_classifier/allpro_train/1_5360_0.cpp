#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<int>>;

class lowest_common_ancestor {
	using pii = pair<int, int>;
	vector<int> depth, par, heavy, head;
	int dfs(int v, int prev, const graph& G) {
		par[v] = prev;
		depth[v] = prev != -1 ? depth[prev] + 1 : 0;
		int ma = 0, cnt = 1;
		for (auto to : G[v]) if (to != prev) {
			int c = dfs(to, v, G);
			if (c > ma) {
				ma = c;
				heavy[v] = to;
			}
			cnt += c;
		}
		return cnt;
	}
public:
	lowest_common_ancestor(const graph& G, int rt = 0)
		: depth(G.size()), par(G.size()), heavy(G.size(), -1), head(G.size()) {
		dfs(rt, -1, G);
		queue<int> q;
		q.push(rt);
		while (!q.empty()) {
			int h = q.front(); q.pop();
			for (int v = h; v != -1; v = heavy[v]) {
				head[v] = h;
				for (auto to : G[v]) if (to != par[v] && to != heavy[v]) {
					q.push(to);
				}
			}
		}
	}
	int calc(int u, int v) {
		while (head[u] != head[v]) {
			if (depth[head[u]] < depth[head[v]]) v = par[head[v]];
			else u = par[head[u]];
		}
		return depth[u] < depth[v] ? u : v;
	}
	int dist(int a, int b) {
		return depth[a] + depth[b] - depth[calc(a, b)] * 2;
	}
};

const int MAX = 1e5;
int dep[MAX];
int vv[MAX];
int lv[MAX], rv[MAX];
int vit;

void euler_tour(int v, int prev, const graph& G) {
	dep[vit] = prev == -1 ? 0 : dep[prev] + 1;
	vv[vit] = v;
	lv[v] = vit++;
	for (auto to : G[v]) if (to != prev) {
		euler_tour(to, v, G);
	}
	rv[v] = vit;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	graph G(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v; --u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	lowest_common_ancestor lc(G);
	euler_tour(0, -1, G);
	vector<set<int>> vs(MAX);
	vector<int> res(MAX, -1);
	auto add = [&](int v, int c) {
		if (vs[c].empty()) {
			vs[c].insert(lv[v]);
			res[c] = 0;
			return;
		}
		auto it = vs[c].lower_bound(lv[v]);
		int pre = vv[it == vs[c].begin() ? *vs[c].rbegin() : *prev(it)];
		int nex = vv[it == vs[c].end() ? *vs[c].begin() : *it];
		vs[c].insert(lv[v]);
		res[c] += (lc.dist(pre, v) + lc.dist(v, nex) - lc.dist(pre, nex)) / 2;
	};
	auto del = [&](int v, int c) {
		vs[c].erase(lv[v]);
		if (vs[c].empty()) {
			res[c] = -1;
			return;
		}
		auto it = vs[c].lower_bound(lv[v]);
		int pre = vv[it == vs[c].begin() ? *vs[c].rbegin() : *prev(it)];
		int nex = vv[it == vs[c].end() ? *vs[c].begin() : *it];
		res[c] -= (lc.dist(pre, v) + lc.dist(v, nex) - lc.dist(pre, nex)) / 2;
	};
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i]; --c[i];
		add(i, c[i]);
	}
	int m;
	cin >> m;
	while (m--) {
		char com;
		cin >> com;
		if (com == 'U') {
			int x, y;
			cin >> x >> y; --x, --y;
			del(x, c[x]);
			add(x, y);
			c[x] = y;
		}
		else {
			int y;
			cin >> y; --y;
			printf("%d\n", res[y]);
		}
	}
	return 0;
}

