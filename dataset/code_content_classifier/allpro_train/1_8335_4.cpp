#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, inf = 0x3f3f3f3f - 10;
int head[maxn], cur[maxn], nxt[maxn << 1], w[maxn << 1], to[maxn << 1];
int cnt = -1, deep[maxn], S, T, n, m;
char s[205][205];
void add(int x, int y, int c) {
  nxt[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
  w[cnt] = c;
  nxt[++cnt] = head[y];
  head[y] = cnt;
  to[cnt] = x;
  w[cnt] = 0;
}
bool bfs() {
  for (int i = 0; i <= T; i++) deep[i] = 0;
  queue<int> q;
  q.push(S);
  deep[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = nxt[i]) {
      int v = to[i];
      if (w[i] > 0 && deep[v] == 0) {
        deep[v] = deep[u] + 1;
        if (v == T) return 1;
        q.push(v);
      }
    }
  }
  return deep[T] != 0;
}
int dfs(int u, int fl) {
  if (u == T) return fl;
  int ans = 0, x = 0;
  for (int i = cur[u]; i != -1; i = nxt[i]) {
    int v = to[i];
    if (w[i] > 0 && deep[v] == deep[u] + 1) {
      x = dfs(v, min(fl - ans, w[i]));
      w[i] -= x;
      w[i ^ 1] += x;
      ans += x;
      if (ans == fl) return ans;
      if (w[i]) cur[u] = i;
    }
  }
  if (ans == 0) deep[u] = 0;
  return ans;
}
int dinic() {
  int res = 0;
  while (bfs()) {
    for (int i = 0; i <= T; i++) cur[i] = head[i];
    res += dfs(S, inf);
  }
  return res;
}
int getid(int i, int j, int ad) { return (i - 1) * m + j + ad; }
int main() {
  scanf("%d%d", &n, &m);
  S = 2 * n * m + 10, T = S + 1;
  for (int i = 0; i <= T; i++) head[i] = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') {
        int L = (j - 1 >= 1 && s[i][j - 1] == '#') ? getid(i, j - 1, 0) : 0;
        int R = (j + 1 <= m && s[i][j + 1] == '#') ? getid(i, j - 1, 1) : 0;
        int U = (i - 1 >= 1 && s[i - 1][j] == '#') ? getid(i - 1, j, n * m) : 0;
        int D =
            (i + 1 <= n && s[i + 1][j] == '#') ? getid(i - 1, j, n * m + m) : 0;
        if (L && U) add(L, U, 1);
        if (L && D) add(L, D, 1);
        if (R && U) add(R, U, 1);
        if (R && D) add(R, D, 1);
      }
    }
  }
  int sum = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') {
        sum++;
        if (j + 1 <= m && s[i][j + 1] == '#')
          add(S, getid(i, j - 1, 1), 1), res++;
        if (i + 1 <= n && s[i + 1][j] == '#')
          add(getid(i - 1, j, n * m + m), T, 1), res++;
      }
    }
  }
  printf("%d\n", sum - (res - dinic()));
  return 0;
}
