#include <algorithm>
#include <cstring>
#include <cstdio>
int dp[100005], seq[100005], deg[100005], lst[100005], to[200005], pre[200005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u];
	deg[v]++; 
	lst[u] = tot++;
}
bool dfs(int u, int lim, int fa = -1)
{
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] != fa && !dfs(to[i], lim, u))
			return false; 
	}
	int len = 0; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] != fa)
			seq[len++] = dp[to[i]] + 1; 
	}
	if (len & 1 ^ (fa != -1))
		seq[len++] = 0; 
	std::sort(seq, seq + len); 
	if (~fa)
	{
		int l = 0, r = len - 2; 
		while (l < r)
		{
			if (seq[l++] + seq[r--] > lim)
				return false; 
		}
		int idx = len - 1; 
		while (idx && seq[idx] + seq[len - 1 - idx + (idx << 1 < len)] <= lim)
			idx--; 
		dp[u] = seq[idx]; 
	}
	else
	{
		int l = 0, r = len - 1; 
		while (l < r)
		{
			if (seq[l++] + seq[r--] > lim)
				return false; 
		}
	}
	return true; 
}
int main()
{
	// freopen("ARC088-F.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v);
		add_edge(v, u); 
	}
	int a = 0, l = 0, r = n - 1, ans; 
	for (int i = 0; i < n; i++)
		a += deg[i] & 1; 
	while (l <= r)
	{
		int m = l + r >> 1; 
		if (dfs(0, m))
		{
			ans = m; 
			r = m - 1; 
		}
		else
			l = m + 1;
	}
	printf("%d %d\n", a + 1 >> 1, ans);
	return 0; 
}
