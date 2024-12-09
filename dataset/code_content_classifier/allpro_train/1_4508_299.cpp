#include <bits/stdc++.h>
using namespace std;
int n, m, best;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {-1, 0, 1, 0, 0};
int a[45][45];
inline bool ok(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(int x, int tot) {
  vector<pair<int, int> > tmp;
  int xx = -1, yy = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (!a[i][j]) {
        xx = i;
        yy = j;
        break;
      }
    if (xx != -1) break;
  }
  if (xx == -1) {
    best = x;
    return;
  }
  if (x + 1 >= best) return;
  for (int i = 0; i < 5; i++) {
    int x1 = xx + dx[i];
    int y1 = yy + dy[i];
    if (ok(x1, y1)) {
      tmp.clear();
      for (int j = 0; j < 5; j++) {
        int x2 = x1 + dx[j];
        int y2 = y1 + dy[j];
        if (ok(x2, y2) && !a[x2][y2]) {
          tmp.push_back(make_pair(x2, y2));
          a[x2][y2] = 1;
        }
      }
      dfs(x + 1, tot + tmp.size());
      for (int j = 0; j < tmp.size(); j++) a[tmp[j].first][tmp[j].second] = 0;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  best = n * m;
  dfs(0, 0);
  printf("%d\n", n * m - best);
  return 0;
}
