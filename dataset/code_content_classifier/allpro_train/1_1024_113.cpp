#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
struct edge{int to, cost;};
vector<edge> graph[100010];
long long dp[100010];

void dfs(int v, int p = -1, long long c = 0)
{
	dp[v] = c;
	for(int i = 0; i < graph[v].size(); i++)
	{
		if (graph[v][i].to == p) continue;
		dfs(graph[v][i].to, v, graph[v][i].cost + c);
	}
}

signed main(void)
{
	int n;
	cin >> n;
	rep(i, n - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	int q, k;
	cin >> q >> k;
	k--;
	dfs(k);
	rep(i, q)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << dp[x] + dp[y] << endl;
	}
	return 0;
}
