#include <iostream>
#include <vector>
using namespace std;

struct StronglyConnectedComponents
{
	int V;
	const vector<vector<int>> &g;
	int num_of_comp;
	vector<int> comp;
	vector<vector<int>> dag;
	vector<vector<int>> group_set;

	vector<vector<int>> rg;
	vector<int> order;
	vector<bool> used;

	StronglyConnectedComponents(const vector<vector<int>> &g) : V(g.size()), g(g) {}

	void calc() {
		num_of_comp = 0;
		comp.assign(V, -1);
		used.assign(V, false);
		order.reserve(V);
		rg.resize(V);
		for (int i = 0; i < V; i++) {
			for (int e : g[i]) {
				rg[e].push_back(i);
			}
		}
		for (int i = 0; i < V; i++) {
			if (!used[i]) dfs1(i);
		}
		for (int i = V-1; i >= 0; i--) {
			const int v = order[i];
			if (comp[v] == -1) {
				dfs2(v);
				num_of_comp++;
			}
		}
		dag.resize(num_of_comp);
		group_set.resize(num_of_comp);
		for (int i = 0; i < V; i++) group_set[comp[i]].push_back(i);
		for (int i = 0; i < V; i++) {
			for (int e : g[i]) {
				const int x = comp[i], y = comp[e];
				if (x != y) dag[x].push_back(y);
			}
		}

	}

	void dfs1(int v) {
		used[v] = true;
		for (int nv : g[v]) {
			if (used[nv]) continue;
			dfs1(nv);
		}
		order.push_back(v);
	}

	void dfs2(int v) {
		comp[v] = num_of_comp;
		for (int nv : rg[v]) {
			if (comp[nv] != -1) continue;
			dfs2(nv);
		}
	}
};

struct TwoSAT
{
	int n;
	bool ok;
	vector<bool> ans;

	vector<vector<int>> g;

	TwoSAT(int n) : n(n), g(2*n) {}

	void add_clause(int i, bool bool_i, int j, bool bool_j) {
		g[2*i + !bool_i].push_back(2*j + bool_j);
		g[2*j + !bool_j].push_back(2*i + bool_i);
	}

	void calc() {
		StronglyConnectedComponents scc(g);
		scc.calc();
		ok = false;
		for (int i = 0; i < n; i++) {
			if (scc.comp[2*i] == scc.comp[2*i + 1]) return;
		}
		ok = true;
		ans.resize(n);
		for (int i = 0; i < n; i++) {
			ans[i] = scc.comp[2*i] < scc.comp[2*i + 1];
		}
	}
};

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	TwoSAT sat(n);
	for(int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (abs(x[i]-x[j]) < d) sat.add_clause(i, 1, j, 1);
			if (abs(x[i]-y[j]) < d) sat.add_clause(i, 1, j, 0);
			if (abs(y[i]-x[j]) < d) sat.add_clause(i, 0, j, 1);
			if (abs(y[i]-y[j]) < d) sat.add_clause(i, 0, j, 0);
		}
	}
	sat.calc();
	if (sat.ok) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			if (sat.ans[i]) cout << y[i] << '\n';
			else cout << x[i] << '\n';
		}
	} else cout << "No" << endl;
	return 0;
}