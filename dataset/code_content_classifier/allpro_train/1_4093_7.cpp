#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int f[N], n, pos[N], num[N], in[N];
vector<pair<int, int>> edge[N];
int visited[N];
queue<pair<int, int>> q;

bool dfs(int u, int k, int fa) {
	num[u] = 1;
	for (auto e : edge[u]) {
		int v = e.first, Edge = e.second;
		if (!visited[Edge] && v != fa) {
			in[v] = Edge;
			if (dfs(v, k, u)) return true;
			num[u] += num[v];
		}
	}
	//cout << u  << ' ' << fa << ' ' << k << ' ' << num[u] << '\n';
	if (num[u] == f[k - 1]) {
		visited[in[u]] = 1;
		q.push({u, k - 1}); q.push({fa, k - 2});
		return true;
	} else if (num[u] == f[k - 2]) {
		visited[in[u]] = 1;
		q.push({fa, k - 1}); q.push({u, k - 2});
		return true;
	}

	return false;
}

bool judge(int k) {
	q.push({1, k});

	while (!q.empty()) {
		int u = q.front().first, k = q.front().second; q.pop();
		if (k >= 2 && !dfs(u, k, 0)) return false;
	}
	return true;
}

void init() {
	f[0] = f[1] = 1;
	pos[1] = 1;
	for (int i = 2; i <= 30; i++) {
		f[i] = f[i - 1] + f[i - 2];
		//cout << f[i] << '\n';
		if (f[i] <= 2e5) pos[f[i]] = i;
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	init();

	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
	}

	if (pos[n] && judge(pos[n])) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
