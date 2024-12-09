#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
int head[19];
struct aa {
  int from, to, nxt;
} p[209];
int l;
bool k[19][19][20009];
bool kto[19];
struct bb {
  int p, q, s, va;
  bool k;
} dp[20009];
void add(int x, int y) {
  p[++l].nxt = head[x];
  p[l].from = x;
  p[l].to = y;
  head[x] = l;
}
void dfs1(int x, int s, int ps, int h) {
  int u = ps & ((1 << n) - 1 - (1 << (x - 1)));
  if (u - (u & (-u)) > 0 || (h != x && u > 0)) {
    if (k[h][x][u] == 1) return;
    k[h][x][u] = 1;
    if (h == x) return;
  }
  if (ps > 0 && x == h) return;
  for (int j = head[x]; j; j = p[j].nxt) {
    if (!(s & (1 << (p[j].to - 1))) || (ps > 0 && p[j].to == h)) {
      dfs1(p[j].to, s | (1 << (p[j].to - 1)), ps | (1 << (p[j].to - 1)), h);
    }
  }
}
int u[19], lu;
bool mach;
void dfs2(int x, int to, int s) {
  if (mach == 1) return;
  if (s == 0) {
    for (int j = head[x]; j; j = p[j].nxt) {
      if (p[j].to == to) {
        u[++lu] = j;
        mach = 1;
        return;
      }
    }
  }
  for (int j = head[x]; j; j = p[j].nxt) {
    if (s & (1 << (p[j].to - 1))) {
      u[++lu] = j;
      dfs2(p[j].to, to, s - (1 << (p[j].to - 1)));
      if (mach == 1) return;
      lu--;
    }
  }
}
void dfs(int s) {
  if ((s - (s & (-s))) == 0) return;
  mach = 0;
  dfs2(dp[s].p, dp[s].q, dp[s].s);
  for (int j = 1; j <= lu; j++) printf("%d %d\n", p[u[j]].from, p[u[j]].to);
  lu = 0;
  dfs(s - dp[s].s);
}
int main() {
  scanf("%d%d", &n, &m);
  int tto[20009], ss[20009];
  for (int j = 1; j <= n; j++) tto[1 << (j - 1)] = j;
  for (int j = 1; j <= (1 << n) - 1; j++) {
    int uuu = j;
    ss[j] = 1;
    while (uuu > 0) {
      uuu -= uuu & (-uuu);
      ss[j]++;
    }
  }
  for (int j = 1; j <= m; j++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  for (int j = 1; j <= n; j++) dfs1(j, 1 << (j - 1), 0, j);
  for (int j = 1; j <= n; j++) dp[1 << (j - 1)].k = 1;
  for (int j = 1; j <= (1 << n) - 1; j++) {
    for (int i = j; i; i -= i & (-i)) {
      for (int qq = j; qq; qq -= qq & (-qq)) {
        x = tto[i & (-i)];
        y = tto[qq & (-qq)];
        if (x < y) continue;
        int ppp = ((1 << n) - 1) ^ j;
        for (int o = ppp; o; o--, o &= ppp) {
          if (k[x][y][o]) {
            int so = ss[o];
            if (dp[j].k == 1 &&
                (dp[j | o].k == 0 || dp[j].va + so < dp[j | o].va)) {
              dp[j | o].va = dp[j].va + so;
              dp[j | o].p = x;
              dp[j | o].q = y;
              dp[j | o].s = o;
              dp[j | o].k = 1;
            }
          }
        }
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1].va);
  int j = (1 << n) - 1;
  dfs(j);
  return 0;
}
