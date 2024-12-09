#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
int n, m;
vector<pair<int, int> > G[maxn], X[maxn];
bool used[maxn];
int co[maxn];
int f[maxn];
int find(int x) { return f[x] = x == f[x] ? x : find(f[x]); }
bool uni_set(int x, int y) {
  int u = find(x), v = find(y);
  if (u == v) return false;
  f[u] = v;
  return true;
}
void gao(int x, int y) {
  if (X[y][0].first == x) co[y] = X[y][0].second;
  if (X[y][1].first == x) co[y] = X[y][1].second;
}
void dfs(int u) {
  if (used[u]) return;
  used[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    pair<int, int> p = G[u][i];
    int v = p.first;
    if (used[v]) continue;
    gao(v, p.second);
    dfs(v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int k;
  for (int i = 0; i < n; i++) {
    f[i] = i;
    scanf("%d", &k);
    int t;
    for (int j = 0; j < k; j++) {
      scanf("%d", &t);
      if (t > 0)
        X[t].push_back(make_pair(i, 1));
      else
        X[-t].push_back(make_pair(i, 0));
    }
  }
  for (int i = 1; i <= m; i++)
    if (X[i].size() == 1) {
      co[i] = X[i][0].second;
      dfs(X[i][0].first);
    } else if (X[i].size() == 2) {
      if (X[i][0].second == X[i][1].second) {
        co[i] = X[i][0].second;
        dfs(X[i][0].first);
        dfs(X[i][1].first);
        uni_set(X[i][0].first, X[i][1].first);
      } else {
        if (used[X[i][0].first]) {
          co[i] = X[i][1].second;
          dfs(X[i][1].first);
          uni_set(X[i][0].first, X[i][1].first);
        } else if (used[X[i][1].first]) {
          co[i] = X[i][0].second;
          dfs(X[i][0].first);
          uni_set(X[i][0].first, X[i][1].first);
        } else if (!uni_set(X[i][0].first, X[i][1].first)) {
          co[i] = X[i][0].second;
          dfs(X[i][0].first);
        } else {
          G[X[i][0].first].push_back(make_pair(X[i][1].first, i));
          G[X[i][1].first].push_back(make_pair(X[i][0].first, i));
          uni_set(X[i][0].first, X[i][1].first);
        }
      }
    }
  bool flag = 1;
  for (int i = 0; i < n; i++) flag &= used[i];
  if (!flag) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= m; i++) printf("%d", co[i]);
  puts("");
  return 0;
}
