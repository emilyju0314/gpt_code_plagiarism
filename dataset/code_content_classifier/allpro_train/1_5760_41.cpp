#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 10;
const int INF = ~0U >> 2;
vector<int> E[MAX_N];
int n, m;
int pre[MAX_N], low[MAX_N], cnt, top, stk[MAX_N];
bool inside[MAX_N];
vector<int> scc[MAX_N];
int belong[MAX_N], num;
void dfs(int x) {
  pre[x] = low[x] = ++cnt;
  stk[++top] = x;
  inside[x] = 1;
  for (int i = 0; i < E[x].size(); i++) {
    int y = E[x][i];
    if (!pre[y]) {
      dfs(y);
      low[x] = min(low[x], low[y]);
    }
    if (inside[y]) low[x] = min(low[x], low[y]);
  }
  if (pre[x] == low[x]) {
    num++;
    for (;;) {
      int fa = stk[top--];
      belong[fa] = num;
      scc[num].push_back(fa);
      inside[fa] = false;
      if (fa == x) break;
    }
  }
}
vector<int> G[MAX_N];
vector<pair<int, int> > ed;
int d[MAX_N];
bool vis[MAX_N];
queue<int> q;
int ret;
void solve(int x) {
  for (int i = 1; i <= n; i++) {
    d[i] = INF;
    vis[i] = 0;
  }
  vis[x] = 1;
  q.push(x);
  d[x] = 0;
  while (q.size()) {
    int y = q.front();
    q.pop();
    for (int i = 0; i < E[y].size(); i++) {
      int z = E[y][i];
      if (!vis[z]) {
        vis[z] = 1;
        d[z] = d[y] + 1;
        q.push(z);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < E[i].size(); j++) {
      int y = E[i][j];
      if (y == x) {
        ret = min(ret, d[i] + 1);
      }
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    ed.push_back(make_pair(a, b));
  }
  for (int i = 1; i <= n; i++)
    if (!pre[i]) dfs(i);
  for (int i = 0; i < m; i++) {
    int a = ed[i].first, b = ed[i].second;
    if (belong[a] != belong[b]) G[belong[a]].push_back(belong[b]);
  }
  int ans = n;
  for (int i = 1; i <= num; i++)
    if (G[i].size() == 0) {
      if (scc[i].size() == 1) continue;
      ret = n;
      for (int j = 0; j < scc[i].size(); j++) solve(scc[i][j]);
      ans += 998 * ret + 1;
    }
  cout << ans << endl;
  return 0;
}
