#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
vector<int> a[N], e[N];
int dfn[N], low[N], Stack[N], num[N], v[N], cnt, tot, n, m, x, y, now, res, ans,
    flag[N];
void dfs(int x, int y) {
  dfn[x] = low[x] = ++cnt;
  Stack[++tot] = x;
  flag[x] = 1;
  for (int i : a[x])
    if (i != y) {
      if (!dfn[i])
        dfs(i, x), low[x] = min(low[x], low[i]);
      else if (flag[i])
        low[x] = min(low[x], dfn[i]);
    }
  if (low[x] == dfn[x]) {
    ++now;
    while (Stack[tot] != x) {
      flag[Stack[tot]] = 0;
      num[Stack[tot]] = now;
      tot--;
    }
    flag[Stack[tot]] = 0;
    num[Stack[tot]] = now;
    tot--;
  }
}
void dfs1(int i, int d) {
  if (v[i] == x) return;
  v[i] = x;
  if (d > res) res = d, y = i;
  for (int j : e[i]) dfs1(j, d + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  ans = n - 1;
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i, 0);
  for (int i = 1; i <= n; i++)
    for (int j : a[i])
      if (num[i] != num[j]) e[num[i]].push_back(num[j]);
  for (int i = 1; i <= now; i++) {
    if (e[i].size() < 2) ans--;
    if (!v[i]) {
      res = 0;
      x = y = i;
      dfs1(x, 0);
      x = y, res = 0;
      dfs1(x, 0);
      ans -= res - 2 + !res;
    }
  }
  printf("%d\n", ans);
}
