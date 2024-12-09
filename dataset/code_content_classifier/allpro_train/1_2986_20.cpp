#include <bits/stdc++.h>
using namespace std;
int n, m, d[4][1005][1005], dist[10][10];
char a[1005][1005];
int viz[1005][1005];
struct cell {
  int l, c;
};
queue<cell> Q;
cell w1, w2, w3;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
inline bool Ok(cell A) {
  if (A.l < 1 || A.l > n || A.c < 1 || A.c > m) return false;
  if (a[A.l][A.c] == '#') return false;
  return true;
}
inline void Fill(cell A, int info) {
  int i, j;
  cell w, w1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) d[info][i][j] = 500000000;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (a[i][j] == a[A.l][A.c]) {
        w.l = i;
        w.c = j;
        Q.push(w);
        d[info][i][j] = 0;
      }
  while (!Q.empty()) {
    w = Q.front();
    Q.pop();
    for (int t = 0; t < 4; ++t) {
      w1.l = w.l + dx[t];
      w1.c = w.c + dy[t];
      if (Ok(w1) && d[info][w1.l][w1.c] > d[info][w.l][w.c] + 1) {
        d[info][w1.l][w1.c] = d[info][w.l][w.c] + 1;
        Q.push(w1);
      }
    }
  }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3')
        dist[info][a[i][j] - '0'] =
            min(dist[info][a[i][j] - '0'], d[info][i][j]);
}
int main() {
  int i, j;
  cin.sync_with_stdio(0);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) cin >> (a[i] + 1);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      if (a[i][j] == '1') {
        w1.l = i;
        w1.c = j;
      }
      if (a[i][j] == '2') {
        w2.l = i;
        w2.c = j;
      }
      if (a[i][j] == '3') {
        w3.l = i;
        w3.c = j;
      }
    }
  for (i = 1; i <= 3; ++i)
    for (j = 1; j <= 3; ++j) dist[i][j] = 500000000;
  Fill(w1, 1);
  Fill(w2, 2);
  Fill(w3, 3);
  int sol = 500000000;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (d[1][i][j] != 500000000 && d[2][i][j] != 500000000 &&
          d[3][i][j] != 500000000)
        sol = min(sol, d[1][i][j] + d[2][i][j] + d[3][i][j] - 2);
  if (dist[1][2] != 500000000 && dist[1][3] != 500000000)
    sol = min(sol, dist[1][2] + dist[1][3] - 2);
  if (dist[2][1] != 500000000 && dist[2][3] != 500000000)
    sol = min(sol, dist[1][2] + dist[2][3] - 2);
  if (dist[3][2] != 500000000 && dist[1][3] != 500000000)
    sol = min(sol, dist[3][2] + dist[1][3] - 2);
  if (sol == 500000000)
    cout << "-1";
  else
    cout << sol;
  return 0;
}
