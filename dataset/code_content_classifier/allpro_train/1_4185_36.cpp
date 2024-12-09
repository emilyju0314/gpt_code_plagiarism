#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1500 + 10;
pair<pair<int, int>, int> point[MAXN];
int n, xcur, ycur, par[MAXN], child[MAXN], ans[MAXN];
bool mrk[MAXN], adj[MAXN][MAXN];
void read() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    adj[v - 1][u - 1] = 1;
    adj[u - 1][v - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    point[i].second = i;
    cin >> point[i].first.first >> point[i].first.second;
  }
  sort(point, point + n);
}
void dfs(int x, int parent) {
  mrk[x] = 1;
  child[x] = 1;
  par[x] = parent;
  for (int i = 0; i < n; i++)
    if (!mrk[i] && adj[x][i]) {
      dfs(i, x);
      child[x] += child[i];
    }
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return ((long long)b.first.first - xcur) *
             ((long long)a.first.second - ycur) <
         ((long long)a.first.first - xcur) * ((long long)b.first.second - ycur);
}
void solve(int node, int l, int r) {
  if (l == r - 1) {
    ans[point[l].second] = node;
    return;
  }
  sort(point + l, point + r);
  ans[point[l].second] = node;
  xcur = point[l].first.first, ycur = point[l].first.second;
  sort(point + l + 1, point + r, cmp);
  int it = l + 1;
  for (int i = 0; i < n; i++)
    if (par[i] == node) {
      solve(i, it, it + child[i]);
      it += child[i];
    }
}
int main() {
  read();
  dfs(0, -1);
  solve(0, 0, n);
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << endl;
  return 0;
}
