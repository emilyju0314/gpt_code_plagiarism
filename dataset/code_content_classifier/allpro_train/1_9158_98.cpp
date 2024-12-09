//In the Name of God
//Ya Ali

#include <bits/stdc++.h>

#define pii pair<int, int> 

#define err(A) cout << #A << " = " << (A) << endl

using namespace std;

const int maxn = 2048;

int n, m;

vector<int> g[maxn];
int d[maxn];

int st[maxn], ft[maxn], T;
int par[maxn];
int dis[maxn][maxn];

bool rev[maxn * 2];
int s[maxn * 2], t[maxn * 2];

int vis[maxn][maxn];

int M;
int q[maxn * maxn * 2], pt;
int l[maxn * 2], r[maxn * 2];

vector<pii> p[maxn];

bool mark[maxn];
bool kild[maxn * 2];

int ans;

void dfs(int v)
{
  st[v] = T ++;
  for(int u: g[v])
    if (u != par[v])
      par[u] = v, dfs(u);
  ft[v] = T ++;
}

int get_dis(int v, int u)
{
  if (~dis[v][u])
    return dis[v][u];
  if (v == u)
    return dis[v][u] = 0;
  if (v == 0)
    return dis[v][u] = get_dis(v, par[u]) + 1;
  else if (u == 0)
    return dis[v][u] = get_dis(par[v], u) + 1;
  return dis[v][u] = min(get_dis(v, par[u]), get_dis(par[v], u)) + 1;
}

void visit(int v, int u)
{
  if (v > u)
    swap(v, u);
  if (vis[v][u] < 2)
    ++ vis[v][u], ans ++;
}

int get_head(int id, int i, int v)
{
  if (r[id] > i + 1 and q[i + 1] == v)
    return q[r[id] - 1];
  else
    return q[l[id]];
}

void add_chain(int id, int x, int y, bool check = false)
{
  if (x == y)
    return;
  s[id] = x, t[id] = y;
  if (st[x] > st[y])
    swap(x, y);

  l[id] = pt;
  for(; ft[x] < ft[y]; x = par[x])
    q[pt ++] = x;
  q[pt ++] = x;
  
  r[id] = pt;
  for(; st[y] > st[x]; y = par[y])
    q[pt ++] = y;
  reverse(q + r[id], q + pt);
  r[id] = pt;

  if (q[l[id]] != s[id])
    reverse(q + l[id], q + r[id]);

  for (int i = l[id]; i < r[id]; i ++)
    p[q[i]].push_back({id, i});

  if (check)
    for (int i = l[id]; i + 1 < r[id]; i ++)
      visit(q[i], q[i + 1]);
}

void set_dir(int id, int v, int u)
{
  if (rev[id])
    swap(v, u);
  if (get_dis(s[id], v) + 1 + get_dis(u, t[id]) != get_dis(s[id], t[id]))
    rev[id] ^= true;
}

bool goes(int id, int i, int v)
{
  if (i + 1 < r[id] and q[i + 1] == v)
    return true;
  if (i - 1 >= l[id] and q[i - 1] == v)
    return true;
  return false;
}

void solve()
{  
  int v = -1, u;
  for (int i = 0; i < n; i ++)
    if (!mark[i] and d[i] == 1)
      v = i;
  if (v == -1)
    return;
  
  for (int o: g[v])
    if (!mark[o])
      u = o;

  mark[v] = true;
  d[u] --;

  int a = -1, b = -1, ai, bi;
  for (pii o: p[v])
    if (!kild[o.first] and goes(o.first, o.second, u))
      if (~a)
	b = o.first, bi = o.second;
      else
	a = o.first, ai = o.second;
  
  if (b == -1)
    {
      solve();
      return;
    }

  set_dir(a, v, u);
  set_dir(b, u, v);
  
  int that = M;
  add_chain(M ++, get_head(b, bi, u), get_head(a, ai, u));
  
  kild[a] = kild[b] = true;

  solve();
  
  rev[a] ^= rev[that];
  rev[b] ^= rev[that];
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n - 1; i ++)
    {
      int v, u;
      cin >> v >> u;
      v --, u --;
      g[v].push_back(u);
      g[u].push_back(v);
      d[v] ++, d[u] ++;
    }

  dfs(0);
  memset(dis, -1, sizeof dis);

  for (int i = 0; i < m; i ++)
    {
      int v, u;
      cin >> v >> u;
      v --, u --;
      add_chain(M ++, v, u, true);
    }
  
  solve();

  cout << ans << "\n";
  
  for (int i = 0; i < m; i ++)
    if (rev[i])
      cout << t[i] + 1 << " " << s[i] + 1 << "\n";
    else
      cout << s[i] + 1 << " " << t[i] + 1 << "\n";
  
  return 0;
}
