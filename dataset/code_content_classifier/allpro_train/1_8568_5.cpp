#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
	int to, cap, rev;
	edge(int t, int c, int r):to(t), cap(c), rev(r){}
};

int n, m;
int s, t;

vector<vector<edge> > G;
vector<int> level;
vector<int> iter;
constexpr int INF = 0xfffffff;

void init(int V) {
	G.assign(V, vector<edge>());
	level.assign(V, 0);
	iter.assign(V, 0);
}

void add_edge(int from, int to, int cap) {
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(int s) {
	fill(level.begin(), level.end(), -1);
	queue<int> que;
	level[s] = 0;
	que.push(s);

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(int i = 0; i < (int)G[v].size(); ++i) {
			const edge& e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if(v == t)
		return f;

	for(int& i = iter[v]; i < (int)G[v].size(); ++i) {
		edge& e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]) {
			const int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}

	return 0;
}

int max_flow(int a, int b) {
	int flow = 0;
	vector<vector<edge>> tmp(G);
	add_edge(a + n, t, 1);
	add_edge(b + n, t, 1);

	for(;;) {
		bfs(s);
		if(level[t] < 0) {
			G = move(tmp);
			return flow;
		}

		fill(iter.begin(), iter.end(), 0);
		int f;
		while((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	init(n + n + 1);
	s = n;
	t = n + n;

	for(int i = 0; i < n; ++i) {
		add_edge(i, i + n, 1);
	}

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		cout << (max_flow(a, b) == 2 ? "Yes" : "No") << endl;
		add_edge(a + n, b, 1);
		add_edge(b + n, a, 1);
	}

	return EXIT_SUCCESS;
}