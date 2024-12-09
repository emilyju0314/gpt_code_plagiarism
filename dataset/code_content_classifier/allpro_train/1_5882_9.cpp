#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef int weight;

struct edge {
	int to;
	weight cap;
	int rev;
	bool is_rev;
	edge(int to_, weight cap_, int rev_, bool is_rev_):to(to_), cap(cap_), rev(rev_), is_rev(is_rev_){}
};

constexpr weight INF = (1 << 29);

vector<vector<edge> > G;
vector<int> level;
vector<int> iter;

void init(int V) {
	G.assign(V, vector<edge>());
	level.resize(V);
	iter.resize(V);
}

void add_edge(int from, int to, weight cap) {
	G[from].emplace_back(to, cap, G[to].size(), false);
	G[to].emplace_back(from, 0, G[from].size() - 1, true);
}

void bfs(int s) {
	fill(level.begin(), level.end(), -1);
	queue<int> que;
	level[s] = 0;
	que.push(s);

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(const auto &e : G[v]) {
			if(e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

weight dfs(int v, int t, weight f) {
	if(v == t) return f;

	for(int &i = iter[v]; i < static_cast<int>(G[v].size()); ++i) {
		edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]) {
			const weight d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}

	return 0;
}

weight max_flow(int s, int t) {
	weight flow = 0;

	for(;;) {
		bfs(s);
		if(level[t] < 0) return flow;

		fill(iter.begin(), iter.end(), 0);
		for(weight f; (f = dfs(s, t, INF)) > 0; flow += f);
	}
}

vector<bool> calc_reach(int s, int ok) {
	const int n = G.size();

	queue<int> que;
	vector<bool> visited(n, false);

	que.push(s);
	visited[s] = true;

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(const auto &e : G[v]) {
			if(e.cap == ok && !visited[e.to]) {
				que.push(e.to);
				visited[e.to] = true;
			}
		}
	}
	
	return visited;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n, m, s, t; cin >> n >> m >> s >> t && n;) {
		--s; --t;
		init(n);
		for(int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			add_edge(a, b, 1);
		}

		const int f = max_flow(s, t);
		const auto reach_s = calc_reach(s, 1);
		const auto reach_t = calc_reach(t, 0);

		int num = 0;
		for(int v = 0; v < n; ++v) {
			if(!reach_t[v]) continue;

			for(const auto &e : G[v]) {
				if(e.cap == 1 && !e.is_rev && reach_s[e.to]) ++num;
			}
		}

		cout << (num ? f + 1 : f) << ' ' << num << endl;
	}


	return EXIT_SUCCESS;
}