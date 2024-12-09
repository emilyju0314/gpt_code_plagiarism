#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int n, m, mod, fa[N * N], pos[N * N];
char s[N][N];
struct Graph {
  int n;
  long long g[N][N];
  void lnk(int x, int y) { g[x][x]++, g[y][y]++, g[x][y]--, g[y][x]--; }
  long long Gauss(int idx) {
    long long ret = 1;
    for (int i = 1; i <= idx - 1; i++) {
      for (int j = i + 1; j <= idx - 1; j++) {
        if (g[j][i]) {
          swap(g[i], g[j]), ret *= -1;
          break;
        }
      }
      for (int j = i + 1; j <= idx - 1; j++) {
        while (g[j][i]) {
          long long w = g[i][i] / g[j][i];
          for (int k = 1; k <= idx - 1; k++)
            g[i][k] = (g[i][k] - w * g[j][k] % mod + mod) % mod;
          swap(g[i], g[j]), ret *= -1;
        }
      }
    }
    for (int i = 1; i <= idx - 1; i++) ret = ret * g[i][i] % mod;
    return (ret % mod + mod) % mod;
  }
} G[2];
void add(long long &x, long long y) { x = (x + y) % mod; }
int id(int x, int y) { return (x - 1) * (m + 1) + y; }
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void merge(int x, int y) {
  int fx = getfa(x), fy = getfa(y);
  if (fx == fy) return;
  fa[fx] = fy;
}
long long solve() {
  for (int i = 1; i <= (n + 1) * (m + 1); i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '/') {
        merge(id(i + 1, j), id(i, j + 1));
      } else if (s[i][j] == '\\') {
        merge(id(i, j), id(i + 1, j + 1));
      }
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      if (getfa(id(i, j)) == id(i, j)) {
        pos[id(i, j)] = ++G[(i + j) & 1].n;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '*') {
        int x = id(i + 1, j), y = id(i, j + 1);
        if (getfa(x) != getfa(y)) {
          x = getfa(x), y = getfa(y);
          x = pos[x], y = pos[y];
          G[(i + 1 + j) & 1].lnk(x, y);
        }
        x = id(i, j), y = id(i + 1, j + 1);
        if (getfa(x) != getfa(y)) {
          x = getfa(x), y = getfa(y);
          x = pos[x], y = pos[y];
          G[(i + j) & 1].lnk(x, y);
        }
      }
    }
  }
  return (G[0].Gauss(G[0].n) + G[1].Gauss(G[1].n)) % mod;
}
int main() {
  cin >> n >> m >> mod;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  printf("%lld\n", solve());
  return 0;
}
