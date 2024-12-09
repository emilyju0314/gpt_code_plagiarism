#include <bits/stdc++.h>
using namespace std;
namespace SETS {
int fa[405];
void init(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
int find_father(int x) { return (fa[x] == x) ? x : fa[x] = find_father(fa[x]); }
bool check(int x, int y) {
  x = find_father(x);
  y = find_father(y);
  return x != y;
}
void merge(int x, int y) {
  x = find_father(x);
  y = find_father(y);
  if (x == y) return;
  fa[x] = y;
}
}  // namespace SETS
char str[25][25];
int id[25][25];
bool kind[405];
int d[1005];
pair<int, int> ee[1005];
bool in[1005];
vector<int> e[1005];
bool spos[1005], tpos[1005];
void build(int n, int m) {
  memset(d, 0, sizeof(d));
  memset(spos, 0, sizeof(spos));
  memset(tpos, 0, sizeof(tpos));
  for (int i = 1; i <= m; i++) vector<int>().swap(e[i]);
  for (int i = 1; i <= m; i++)
    if (in[i]) {
      if (kind[ee[i].first]) d[ee[i].first]++;
      if (kind[ee[i].second]) d[ee[i].second]++;
    }
  for (int i = 1; i <= m; i++)
    if (in[i]) {
      SETS::init(n);
      for (int j = 1; j <= m; j++)
        if (in[j] && j != i) SETS::merge(ee[j].first, ee[j].second);
      if (kind[ee[i].first]) d[ee[i].first]--;
      if (kind[ee[i].second]) d[ee[i].second]--;
      for (int j = 1; j <= m; j++)
        if (!in[j]) {
          int u = ee[j].first, v = ee[j].second;
          if (!kind[u] && !kind[v]) continue;
          if (SETS::check(u, v)) e[i].push_back(j);
          if ((!kind[u] || d[u] < 2) && (!kind[v] || d[v] < 2))
            e[j].push_back(i);
        }
      if (kind[ee[i].first]) d[ee[i].first]++;
      if (kind[ee[i].second]) d[ee[i].second]++;
    }
  SETS::init(n);
  for (int i = 1; i <= m; i++)
    if (in[i]) SETS::merge(ee[i].first, ee[i].second);
  for (int i = 1; i <= m; i++)
    if (!in[i]) {
      int u = ee[i].first, v = ee[i].second;
      if (!kind[u] && !kind[v]) continue;
      if (SETS::check(u, v)) spos[i] = 1;
      if ((!kind[u] || d[u] < 2) && (!kind[v] || d[v] < 2)) tpos[i] = 1;
    }
}
bool vis[1005];
int p[1005];
queue<int> q;
bool bfs(int n) {
  while (!q.empty()) q.pop();
  memset(vis, 0, sizeof(vis));
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= n; i++)
    if (spos[i]) {
      vis[i] = 1;
      q.push(i);
    }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (tpos[x]) {
      for (int i = x; i; i = p[i]) in[i] ^= 1;
      return 1;
    }
    for (int i = 0; i < e[x].size(); i++)
      if (!vis[e[x][i]]) {
        int u = e[x][i];
        vis[u] = 1;
        p[u] = x;
        q.push(u);
      }
  }
  return 0;
}
char ans[45][45];
pair<int, int> pos[405];
int main() {
  int cases;
  scanf("%d", &cases);
  for (; cases; cases--) {
    memset(id, 0, sizeof(id));
    memset(kind, 0, sizeof(kind));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (str[i][j] == 'O') {
          id[i][j] = ++cnt;
          kind[cnt] = ((i != 1 || j != 1) && (!((i + j) & 1)));
          pos[cnt] = pair<int, int>(i, j);
        }
    int sz = 0, s = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (str[i][j] == 'O') {
          s += kind[id[i][j]];
          if (j < m && str[i][j + 1] == 'O')
            ee[++sz] = pair<int, int>(id[i][j], id[i][j + 1]);
          if (i < n && str[i + 1][j] == 'O')
            ee[++sz] = pair<int, int>(id[i][j], id[i + 1][j]);
        }
    memset(in, 0, sizeof(in));
    bool ok = 1;
    for (int i = 1; i <= 2 * s; i++) {
      build(cnt, sz);
      if (!bfs(sz)) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    puts("YES");
    SETS::init(cnt);
    for (int i = 1; i <= sz; i++)
      if (in[i]) SETS::merge(ee[i].first, ee[i].second);
    for (int i = 1; i <= sz; i++)
      if (!in[i] && SETS::check(ee[i].first, ee[i].second)) {
        in[i] = 1;
        SETS::merge(ee[i].first, ee[i].second);
      }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans[2 * i - 1][2 * j - 1] = str[i][j];
    for (int i = 1; i <= sz; i++)
      if (in[i]) {
        int u = ee[i].first, v = ee[i].second;
        if (pos[u].first == pos[v].first)
          ans[2 * pos[u].first - 1][2 * pos[u].second] = 'O';
        else
          ans[2 * pos[u].first][2 * pos[u].second - 1] = 'O';
      }
    for (int i = 1; i <= 2 * n - 1; i++) {
      for (int j = 1; j <= 2 * m - 1; j++)
        putchar((ans[i][j]) ? ans[i][j] : ' ');
      putchar('\n');
    }
  }
  return 0;
}
