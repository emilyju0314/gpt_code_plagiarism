#include <bits/stdc++.h>
const int N = 155, K = 31, inf = 2e9;
using namespace std;
struct edge {
  int x, y, z;
  bool operator<(const edge b) const { return z < b.z; }
} g[N];
struct node {
  int x, y;
} q[N];
bitset<N> c, f[K][N];
bool v[N][N];
int k[N], d[N];
int n, su;
inline int read() {
  char h = getchar();
  int y = 0;
  while (h < '0' || h > '9') h = getchar();
  while (h >= '0' && h <= '9') y = y * 10 + h - '0', h = getchar();
  return y;
}
inline void mul(int d) {
  bitset<N> t;
  for (int i = 1; i <= n; i++)
    if (c[i]) t |= f[d][i];
  c = t;
}
inline void modify(int b) {
  for (int i = 0; i < K; i++)
    if ((b >> i) & 1) mul(i);
}
void change(int x, int y, int d) {
  if (d == K) return;
  if (f[d][x][y]) return;
  f[d][x][y] = 1;
  for (int i = 1; i <= n; i++) {
    if (f[d][i][x]) change(i, y, d + 1);
    if (f[d][y][i]) change(x, i, d + 1);
  }
}
inline void add(int a, int b) {
  q[++su] = (node){k[a], b};
  k[a] = su;
}
inline long long bfs() {
  queue<int> dl;
  for (int i = 1; i <= n; i++) d[i] = inf;
  for (int i = 1; i <= n; i++)
    if (c[i]) dl.push(i), d[i] = 0;
  while (!dl.empty()) {
    int x = dl.front();
    dl.pop();
    for (int i = k[x]; i; i = q[i].x) {
      int y = q[i].y;
      if (d[x] + 1 < d[y]) {
        d[y] = d[x] + 1;
        if (y == n) return d[n];
        dl.push(y);
      }
    }
  }
  return inf;
}
signed main() {
  n = read();
  int m = read();
  for (int i = 1; i <= m; i++)
    g[i].x = read(), g[i].y = read(), g[i].z = read();
  sort(g + 1, g + 1 + m);
  c[1] = 1;
  long long ans = inf;
  for (int i = 1; i <= m; i++) {
    modify(g[i].z - g[i - 1].z);
    add(g[i].x, g[i].y);
    change(g[i].x, g[i].y, 0);
    if (!c.any()) break;
    long long t = bfs() + g[i].z;
    if (t < ans) ans = t;
  }
  ans == inf ? puts("Impossible") : printf("%lld\n", ans);
}
