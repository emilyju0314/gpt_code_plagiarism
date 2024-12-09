#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1650;
int xxxxx1, yyyyy1;
int n, m;
bool a[MAXN][MAXN];
bool f[MAXN][MAXN], tf[MAXN][MAXN];
pair<int, int> h[MAXN * MAXN], q[MAXN * MAXN];
int qq, qh;
int dep[MAXN][MAXN];
vector<int> ans;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
inline bool trans(int x, int y, int k) {
  xxxxx1 = x + dx[k];
  yyyyy1 = y + dy[k];
  if (xxxxx1 < 1 || xxxxx1 > n) return 0;
  if (yyyyy1 < 1 || yyyyy1 > m) return 0;
  return 1;
}
inline void BFS(int x2, int y2) {
  q[qq = 1] = pair<int, int>(x2, y2);
  f[x2][y2] = 1;
  for (int i = (1); i <= (int)qq; i++) {
    int x = q[i].first;
    int y = q[i].second;
    for (int k = (1); k <= (int)4; k++)
      if (trans(x, y, k)) {
        if (f[xxxxx1][yyyyy1]) continue;
        if (!a[xxxxx1][yyyyy1]) continue;
        f[xxxxx1][yyyyy1] = 1;
        q[++qq] = pair<int, int>(xxxxx1, yyyyy1);
      }
  }
}
inline int work(int x2, int y2) {
  h[qh = 1] = pair<int, int>(x2, y2);
  tf[x2][y2] = 1;
  dep[x2][y2] = 0;
  for (int i = (1); i <= (int)qh; i++) {
    int x = h[i].first;
    int y = h[i].second;
    if (dep[x][y] == dep[h[qh].first][h[qh].second] && i < qh - 5) break;
    for (int k = (1); k <= (int)4; k++)
      if (trans(x, y, k)) {
        if (tf[xxxxx1][yyyyy1]) continue;
        if (!a[xxxxx1][yyyyy1]) continue;
        tf[xxxxx1][yyyyy1] = 1;
        h[++qh] = pair<int, int>(xxxxx1, yyyyy1);
        dep[xxxxx1][yyyyy1] = dep[x][y] + 1;
      }
  }
  int D = dep[h[qh].first][h[qh].second];
  if (D <= 10) {
    for (int i = (1); i <= (int)qh; i++) tf[h[i].first][h[i].second] = 0;
  }
  return D > 10;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (int)n; i++)
    for (int j = (1); j <= (int)m; j++) scanf("%d", &a[i][j]);
  for (int i = (1); i <= (int)n; i++)
    for (int j = (1); j <= (int)m; j++)
      if (a[i][j] && !f[i][j]) {
        BFS(i, j);
        int s = work(i, j);
        for (int k = (qq); k >= (int)2; k--)
          if (!tf[q[k].first][q[k].second]) s += work(q[k].first, q[k].second);
        ans.push_back(s);
      }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = (0); i <= (int)ans.size() - 1; i++) printf("%d ", ans[i]);
  return 0;
}
