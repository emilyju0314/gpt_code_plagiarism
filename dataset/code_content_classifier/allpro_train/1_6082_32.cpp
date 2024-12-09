#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = (3e5 + 10) * 2;

struct node
{
    int v, next;
} e[N];
int head[N], tot = 1;
void add(int u, int v)
{
    e[++tot].v = v;
    e[tot].next = head[u], head[u] = tot;
}
int n, k;
int nxt[N], fa[N], indeg[N];
int findfa(int x)
{
    if (x != fa[x])
        fa[x] = findfa(fa[x]);
    return fa[x];
}

int vis[N];
bool dfs(int u)
{
    vis[u] = 1;
    for (int x = head[u]; x; x = e[x].next)
    {
        int v = e[x].v;
        if (vis[v] == 2||findfa(u) != findfa(v))
            continue;
        if (vis[v] == 1 || !dfs(v))
            return false;
    }
    vis[u] = 2;
    return true;
}

bool check() //找环
{
    for (int u = 1; u <= n; u++)
        if (u == fa[u] && !dfs(u))
            return false;
    return true;
}

int ans[N], cnt = 0;
bool solve()
{
    for (int u = 0; u <= n; u++)
    {
        for (int x = head[u]; x; x = e[x].next)
        {
            int v = e[x].v;
            int a = findfa(u), b = findfa(v);
            if (a != b) indeg[b]++;
        }
    }
    deque<int> dq;
    dq.push_back(0);
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if (u) ans[++cnt] = u;
        if (nxt[u])
            dq.push_front(nxt[u]); //当前链的优先级永远是最高的
        for (int x = head[u]; x; x = e[x].next)
        {
            int v = e[x].v;
            int a = findfa(u), b = findfa(v);
            if (a != b && --indeg[b] == 0)
                dq.push_back(b);
        }
    }
    return cnt == n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int v = 1, u; v <= n; v++)
    {
        fa[v] = v; cin >> u;
        add(u, v);
    }
    for (int i = 1, u, v; i <= k; i++)
    {
        cin >> u >> v;
        add(u, v);
        nxt[u] = v; //保存并查集内顺序
        fa[findfa(v)] = findfa(u);
    }
    if (check() && solve())
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
    else
        cout << 0 << "\n";
    return 0;
}