#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, mod = 1e9 + 7;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int fr[N], to[N], nt[N], w[N], hd[N], tot = 1;
void adde(int x, int y, int z) {
  ++tot, fr[tot] = x, to[tot] = y, nt[tot] = hd[x], w[tot] = z, hd[x] = tot;
}
int n, m, pt, di[N], de[N], nd, st[N], tp, sq[N], ts;
bool vs[N];
bool cmp(int aa, int bb) { return w[aa] < w[bb]; }
queue<int> q[7];
int main() {
  pt = n = rd(), m = rd();
  for (int i = 1; i <= m; ++i) {
    int x = rd(), y = rd();
    tp = 0;
    int z = i, np = x, p;
    while (z) st[++tp] = z % 10, z /= 10;
    for (int j = tp; j; --j) p = j > 1 ? ++pt : y, adde(np, p, st[j]), np = p;
    np = y;
    for (int j = tp; j; --j) p = j > 1 ? ++pt : x, adde(np, p, st[j]), np = p;
  }
  memset(de, 0x3f3f3f, sizeof(int) * (pt + 1));
  de[1] = di[1] = 0, nd = 0, q[nd].push(1);
  while (1) {
    while (nd < 1145141 && q[nd % 7].empty()) ++nd;
    if (nd == 1145141) break;
    while (!q[nd % 7].empty()) {
      ts = tp = 0;
      while (!q[nd % 7].empty() && (!tp || di[q[nd % 7].front()] == di[st[tp]]))
        st[++tp] = q[nd % 7].front(), q[nd % 7].pop();
      while (tp) {
        int x = st[tp--];
        if (vs[x]) continue;
        vs[x] = 1;
        for (int i = hd[x]; i; i = nt[i]) sq[++ts] = i;
      }
      sort(sq + 1, sq + ts + 1, cmp);
      for (int i = 1; i <= ts; ++i) {
        int j = sq[i], x = fr[j], y = to[j];
        if (de[y] > de[x] + 1) {
          de[y] = de[x] + 1, di[y] = (10ll * di[x] + w[j]) % mod;
          q[de[y] % 7].push(y);
        }
      }
    }
  }
  for (int i = 2; i <= n; ++i) printf("%d\n", di[i]);
  return 0;
}
