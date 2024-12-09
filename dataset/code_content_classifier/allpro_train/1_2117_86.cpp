#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
int a[maxn][maxn], m, n, b[maxn][maxn];
char buf[maxn];
bool mark[5];
void solve(int x1, int x2, bool rotated = 0) {
  memset(mark, 1, sizeof(mark));
  int y1, y2;
  mark[x1] = 0;
  mark[x2] = 0;
  y1 = -1;
  for (int i = 1, _c = 4; i <= _c; i++)
    if (mark[i])
      if (y1 == -1)
        y1 = i;
      else
        y2 = i;
  int u, v;
  for (int i = 1, _c = m; i <= _c; i++) {
    if (i & 1)
      u = x1, v = x2;
    else
      u = y1, v = y2;
    bool ok = 1;
    for (int j = 1, _c = n; j <= _c; j++) {
      b[i][j] = (j & 1) ? u : v;
      if (a[i][j] && a[i][j] != b[i][j]) {
        ok = 0;
        break;
      }
    }
    if (ok) continue;
    ok = 1;
    for (int j = 1, _c = n; j <= _c; j++) {
      b[i][j] = (j & 1) ? v : u;
      if (a[i][j] && a[i][j] != b[i][j]) {
        ok = 0;
        break;
      }
    }
    if (!ok) return;
  }
  if (rotated) {
    for (int j = 1, _c = n; j <= _c; j++) {
      for (int i = 1, _c = m; i <= _c; i++) printf("%d", b[i][j]);
      puts("");
    }
  } else {
    for (int i = 1, _c = m; i <= _c; i++) {
      for (int j = 1, _c = n; j <= _c; j++) printf("%d", b[i][j]);
      puts("");
    }
  }
  exit(0);
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1, _c = m; i <= _c; i++) {
    scanf("%s", buf + 1);
    for (int j = 1, _c = n; j <= _c; j++) a[i][j] = buf[j] - '0';
  }
  for (int i = 1, _c = 3; i <= _c; i++)
    for (int j = i + 1, _c = 4; j <= _c; j++) solve(i, j);
  for (int i = 1, _c = m; i <= _c; i++)
    for (int j = 1, _c = n; j <= _c; j++) b[j][i] = a[i][j];
  swap(m, n);
  for (int i = 1, _c = m; i <= _c; i++)
    for (int j = 1, _c = n; j <= _c; j++) a[i][j] = b[i][j];
  for (int i = 1, _c = 3; i <= _c; i++)
    for (int j = i + 1, _c = 4; j <= _c; j++) solve(i, j, 1);
  puts("0");
  return 0;
}
