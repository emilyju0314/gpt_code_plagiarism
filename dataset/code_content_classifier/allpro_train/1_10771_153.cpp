#include <bits/stdc++.h>
using namespace std;
int a[45][45], mp[45][45], n, m, ans = -2147483647;
int nw(int x, int y) { return -(a[x][y] * 2 - 1) * mp[x][y]; }
int query(int x, int y, int k) {
  a[x][y] = k;
  a[x + m][y] = a[m][y] ^ k;
  a[x][y + m] = a[x][m] ^ k;
  a[x + m][y + m] = a[m][y + m] ^ a[x][y + m];
  return nw(x, y) + nw(x + m, y) + nw(x, y + m) + nw(x + m, y + m);
}
int qaq(int y, int k) {
  int s = 0;
  a[m][y] = k;
  a[m][y + m] = a[m][m] ^ k;
  s += nw(m, y) + nw(m, y + m);
  for (int x = 1; x < m; x++) s += max(query(x, y, 0), query(x, y, 1));
  return s;
}
int qwq() {
  int s = 0;
  for (int x = 1; x <= n; x++) s += nw(x, m);
  for (int y = 1; y < m; y++) s += max(qaq(y, 0), qaq(y, 1));
  return s;
}
int main() {
  scanf("%d", &n);
  m = (n + 1) / 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &mp[i][j]);
  for (int i = 0; i < (1 << m); i++) {
    for (int j = 1; j <= m; j++) a[j][m] = i >> (j - 1) & 1;
    for (int j = 1; j < m; j++) a[j + m][m] = a[m][m] ^ a[j][m];
    ans = max(ans, qwq());
  }
  printf("%d", ans);
  return 0;
}
