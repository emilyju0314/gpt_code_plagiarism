#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, l, r, i, j, f[2][N][26], p[2][N][26];
char c[N];
int bi[26][N];
inline void mdy(int o, int x, int v) {
  if (o == 3) ++o, --o;
  for (; x <= n; x += x & -x) bi[o][x] ^= v;
}
inline int ask(int o, int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans ^= bi[o][x];
  return ans;
}
struct node {
  int l, r, o, c;
} a[N * 55];
int xb;
inline int query(int l, int r) {
  if (l + 1 == r) return 0;
  static int buc[28];
  memset(buc, 0, sizeof buc);
  int y, z, i;
  for (i = 0; i < 26; ++i)
    if (y = p[1][l][i], y && y < r)
      z = p[0][r][i],
      ++buc[f[1][l][i] ^ f[0][r][i] ^ (y == z ? 0 : ask(i, z) ^ ask(i, y))];
  for (i = 0; buc[i]; ++i)
    ;
  return i;
}
int main() {
  scanf("%s%d", c + 1, &m);
  n = strlen(c + 1);
  for (i = 2; i <= n + 1; ++i) {
    memcpy(p[0][i], p[0][i - 1], 104), p[0][i][c[i - 1] - 'a'] = i - 1;
    for (j = 0; j < 26; ++j)
      if (p[0][i][j]) a[++xb] = (node){p[0][i][j], i, 0, j};
  }
  for (i = n - 1; i >= 0; --i) {
    memcpy(p[1][i], p[1][i + 1], 104), p[1][i][c[i + 1] - 'a'] = i + 1;
    for (j = 0; j < 26; ++j)
      if (p[1][i][j]) a[++xb] = (node){i, p[1][i][j], 1, j};
  }
  sort(a + 1, a + xb + 1,
       [&](const node& a, const node& b) { return a.r - a.l < b.r - b.l; });
  memset(f, -1, sizeof f);
  for (i = 1; i <= xb; ++i) {
    if (1 <= a[i].l && a[i].r <= n && c[a[i].l] == c[a[i].r]) {
      int &x = f[1][a[i].l][a[i].c], &y = f[0][a[i].r][a[i].c];
      if (x != -1) {
        y = x;
        continue;
      }
      if (y != -1) {
        x = y;
        continue;
      }
    }
    int& v = a[i].o == 1 ? f[1][a[i].l][a[i].c] : f[0][a[i].r][a[i].c];
    v = query(a[i].l, a[i].r);
    if (1 <= a[i].l && a[i].r <= n && c[a[i].l] == c[a[i].r])
      mdy(c[a[i].l] - 'a', a[i].r, v);
  }
  for (; m--;)
    scanf("%d%d", &l, &r), puts(query(l - 1, r + 1) ? "Alice" : "Bob");
  return 0;
}
