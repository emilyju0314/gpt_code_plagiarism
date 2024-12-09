#include <bits/stdc++.h>
using namespace std;
int n, a, b, da, db;
struct side {
  int t, next;
} s[200005];
int r[100005], num;
inline void add(int x, int y) {
  s[num].t = y;
  s[num].next = r[x];
  r[x] = num++;
  s[num].t = x;
  s[num].next = r[y];
  r[y] = num++;
}
int dfs(int x, int l) {
  if (x == b) return 0;
  for (int i = r[x]; i != -1; i = s[i].next) {
    if (s[i].t != l) {
      int res = dfs(s[i].t, x);
      if (res != -1) return res + 1;
    }
  }
  return -1;
}
int f[100005], g[100005];
int dfs2(int x, int l) {
  f[x] = g[x] = 0;
  int u = 0, v = 0, w;
  for (int i = r[x]; i != -1; i = s[i].next) {
    if (s[i].t == l) continue;
    w = dfs2(s[i].t, x) + 1;
    g[x] = max(g[x], g[s[i].t]);
    if (w >= u) {
      v = u;
      u = w;
    } else if (w > v)
      v = w;
  }
  f[x] = u;
  g[x] = max(g[x], u + v);
  return u;
}
int main() {
  int tt = 0;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    memset(r, -1, sizeof(int) * (n + 4));
    for (int i = 1, j, k; i < n; i++) {
      scanf("%d%d", &j, &k);
      add(j, k);
    }
    if (db <= da * 2) {
      puts("Alice");
      continue;
    }
    if (dfs(a, -1) <= da) {
      puts("Alice");
      continue;
    }
    dfs2(1, -1);
    if (g[1] <= da * 2) {
      puts("Alice");
      continue;
    }
    puts("Bob");
  }
  return 0;
}
