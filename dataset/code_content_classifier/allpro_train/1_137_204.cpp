#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int n;
int m;
string g[5000];
int v[5000][4], t[5000];
int was[5000];
int ct;
int go(int i, int j, int t) {
  if (i < 0 || j < 0 || i >= n || j >= m) return 0;
  if (was[i * m + j] != ct && g[i][j] != '.') return 0;
  return v[i * m + j][t] = v[i * m + j][t] + go(i + dx[t] * v[i * m + j][t],
                                                j + dy[t] * v[i * m + j][t], t);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> g[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      t[i * m + j] = int(g[i][j] == 'U') + 2 * int(g[i][j] == 'R') +
                     3 * int(g[i][j] == 'D') + 4 * int(g[i][j] == '.');
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] != '.') {
        for (int a = 0; a < n; a++)
          for (int b = 0; b < m; b++)
            for (int k = 0; k < 4; k++) v[a * m + b][k] = 1;
        ct++;
        int a = i, b = j, cur = 0;
        while (true) {
          cur++;
          was[a * m + b] = ct;
          int tt = t[a * m + b];
          int d = go(a, b, tt);
          if (a + dx[tt] * d < 0 || a + dx[tt] * d >= n || b + dy[tt] * d < 0 ||
              b + dy[tt] * d >= m)
            break;
          a += dx[tt] * d;
          b += dy[tt] * d;
        }
        if (cur > ans) ans = cur, cnt = 0;
        if (cur == ans) cnt++;
      }
  printf("%d %d\n", ans, cnt);
  return 0;
}
