#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define maxn 100010
#define maxm 800010
typedef long long ll;
struct Edge {
	Edge *next;
	int to, w;
} *last[maxn], e[maxm], *ecnt = e;
inline void link(int a, int b, int w)
{
	*++ecnt = (Edge) {last[a], b, w}; last[a] = ecnt;
	*++ecnt = (Edge) {last[b], a, w}; last[b] = ecnt;
}
ll d[maxn];
int fa[maxn];
int n, m, s, t;
ll f[maxn];
struct Node *null;
struct Node {
	Node *ch[2];
	ll val, tag;
	int lca;
	inline void set_tag(ll tg)
	{
		val += tg;
		tag += tg;
	}
	inline void pushdown()
	{
		if (tag)
		{
			if (ch[0] != null) ch[0] -> set_tag(tag);
			if (ch[1] != null) ch[1] -> set_tag(tag);
			tag = 0;
		}
	}
} *root[maxn], mem[maxm], *tot = mem;
Node *merge(Node *a, Node *b)
{
	if (a == mem) return b;
	if (b == mem) return a;
	if (a -> val > b -> val) std::swap(a, b);
	a -> pushdown();
	std::swap(a -> ch[0], a -> ch[1]);
	a -> ch[1] = merge(a -> ch[1], b);
	return a;
}
int son[maxn], size[maxn], top[maxn], dep[maxn], inv[maxn], dfn[maxn], timer;
void dfs1(int x)
{
	size[x] = 1; dep[x] = dep[fa[x]] + 1;
	for (Edge *iter = last[x]; iter; iter = iter -> next)
		if (fa[iter -> to] == x)
		{
			dfs1(iter -> to);
			size[x] += size[iter -> to];
			size[iter -> to] > size[son[x]] ? son[x] = iter -> to : 0;
		}
}
void dfs2(int x)
{
	top[x] = son[fa[x]] == x ? top[fa[x]] : x;
	dfn[x] = ++timer;
	for (Edge *iter = last[x]; iter; iter = iter -> next)
		if (fa[iter -> to] == x) dfs2(iter -> to);
	inv[x] = timer;
}
inline int getlca(int a, int b)
{
	while (top[a] != top[b])
		dep[top[a]] < dep[top[b]]
			? b = fa[top[b]]
			: a = fa[top[a]];
	return dep[a] < dep[b] ? a : b;
}
void dfs(int x)
{
	root[x] = mem;
	for (Edge *iter = last[x]; iter; iter = iter -> next)
		if (fa[iter -> to] == x)
		{
			dfs(iter -> to);
			if (root[iter -> to] != null) root[iter -> to] -> set_tag(iter -> w);
			root[x] = merge(root[x], root[iter -> to]);
		}
		else if (iter -> to != fa[x])
		{
			*++tot = (Node) {{mem, mem}, d[iter -> to] + iter -> w, 0, getlca(x, iter -> to)};
			root[x] = merge(root[x], tot);
		}
	while (root[x] != null && dfn[x] <= dfn[root[x] -> lca] && dfn[root[x] -> lca] <= inv[x])
		root[x] = merge(root[x] -> ch[0], root[x] -> ch[1]);
	f[x] = root[x] -> val;
}
struct Queue {
	ll d; int x;
	inline bool operator < (const Queue &that) const {return d > that.d;}
} ;
std::priority_queue<Queue> q;
inline bool check(ll mid)
{
	 memset(d, 63, sizeof (d));
	 const ll inf = d[0];
	 q.push((Queue) {d[s] = 0, s});
	 while (!q.empty())
	 {
	 	Queue now = q.top(); q.pop();
	 	if (now.d != d[now.x]) continue;
	 	int x = now.x;
	 	if (d[x] + f[x] > mid) continue;
	 	for (Edge *iter = last[x]; iter; iter = iter -> next)
	 		if (d[iter -> to] > d[x] + iter -> w)
	 		{
	 			d[iter -> to] = d[x] + iter -> w;
	 			q.push((Queue) {d[iter -> to], iter -> to});
	 		}
	 }
	 return d[t] != inf;
}
int main()
{
	null = mem; mem -> val = ~0ULL >> 3; mem -> ch[0] = mem -> ch[1] = mem;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; ++i)
	{
		int a, b, w; scanf("%d%d%d", &a, &b, &w);
		link(a, b, w);
	}
	memset(d, 63, sizeof (d));
	q.push((Queue) {d[t] = 0, t});
	while (!q.empty())
	{
		Queue now = q.top(); q.pop();
		if (now.d != d[now.x]) continue;
		int x = now.x;
		for (Edge *iter = last[x]; iter; iter = iter -> next)
			if (d[iter -> to] > d[x] + iter -> w)
			{
				d[iter -> to] = d[x] + iter -> w;
				q.push((Queue) {d[iter -> to], iter -> to});
			}
	}

	for (int i = 1; i <= n; ++i)
		for (Edge *iter = last[i]; iter; iter = iter -> next)
			if (d[iter -> to] == d[i] + iter -> w)
				fa[iter -> to] = i;

	dfs1(t);
	dfs2(t);
	dfs(t);
//	for (int i = 1; i <= n; ++i) printf("%lld\n", f[i]);
	ll left = 0, right = 1e18;
	while (left < right)
	{
		ll mid = left + right >> 1;
		if (check(mid)) right = mid;
		else left = mid + 1;
	}
	printf("%lld\n", left > 1e17 ? -1 : left);
	return 0;
}
