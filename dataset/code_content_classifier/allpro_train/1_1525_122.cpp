#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, -1, 1};
int d, n, m;
bool was[4000000];
int gr[4000000][3];
queue<int> q;
inline int C(int x, int y) {
  int d = 0;
  if (x == 0) return y;
  d += m;
  if (y == 0) return x + d;
  d += n - 1;
  if (x == n - 1) return y + d;
  d += m - 1;
  return x + d;
}
int tmp[4];
inline void Add(int x, int y) {
  int a, b;
  int c = C(x, y);
  tmp[0] = x;
  tmp[1] = n - x - 1;
  tmp[2] = y;
  tmp[3] = m - y - 1;
  sort(tmp, tmp + 4);
  for (int j = 0; j < 4; j++)
    if ((j == 0 || tmp[j] != tmp[j - 1]) && tmp[j] != 0)
      for (int i = 0; i < 4; i++) {
        a = x + dx[i] * tmp[j];
        b = y + dy[i] * tmp[j];
        if (a < 0 || a > n - 1 || b < 0 || b > m - 1) continue;
        if (!(a == 0 || a == n - 1 || b == 0 || b == m - 1)) continue;
        int nc = C(a, b);
        gr[c][gr[c][2]++] = (nc);
      }
}
int main() {
  cin >> n >> m;
  d = min(n, m) - 1;
  memset(gr, 0, sizeof(gr));
  for (int i = 0; i < n; i++) {
    int x = i;
    int y;
    for (int j = 0; j < 2; j++) {
      if (j == 0)
        y = 0;
      else
        y = m - 1;
      Add(x, y);
    }
  }
  for (int i = 1; i < m - 1; i++) {
    int x;
    int y = i;
    for (int j = 0; j < 2; j++) {
      if (j == 0)
        x = 0;
      else
        x = n - 1;
      Add(x, y);
    }
  }
  memset(was, false, sizeof(was));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (gr[i][2] == 0) continue;
    if (was[i]) continue;
    ans++;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int j = 0; j < gr[v][2]; j++)
        if (!was[gr[v][j]]) {
          q.push(gr[v][j]);
          was[gr[v][j]] = true;
        }
    }
  }
  cout << ans << endl;
  return 0;
}
