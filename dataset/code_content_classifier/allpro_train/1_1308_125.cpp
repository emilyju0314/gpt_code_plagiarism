#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<vector<int>> G(100000);
vector<bool> visit(100000, false);
vector<int> prenum(100000), parent(100000,-1), lowest(100000);
int timer = 1;

void dfs(int u, int prev) {
	prenum[u] = lowest[u] = timer++;
	visit[u] = true;
	for (int v : G[u]) {
		if (!visit[v]) {
			parent[v] = u;
			dfs(v, u);
			lowest[u] = min(lowest[u], lowest[v]);
		}
		else if (v != prev) {
			lowest[u] = min(lowest[u], prenum[v]);
		}
	}
}

int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	set<int> Ans;
	for (int i = 0; i < E;i++) {
		int s, t; cin >> s >> t;
		G[s].emplace_back(t);
		G[t].emplace_back(s);
	}
	dfs(0, -1);

	int count = 0;
	for (int i = 0; i < V;i++) { 
		if (parent[i] == 0) count++;
		if (count >= 2) {
			Ans.insert(0); break;
		}
	}

	for (int i = 1; i < V;i++) {
		for (int v : G[i]) {
			int p = parent[v];
			if (p > 0) {
				if (prenum[p] <= lowest[v])Ans.insert(p);
			}
		}
	}

	for (int i : Ans) {
		cout << i << endl;
	}
}