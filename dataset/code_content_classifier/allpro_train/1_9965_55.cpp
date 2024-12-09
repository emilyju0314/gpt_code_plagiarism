#include <bits/stdc++.h>
using namespace std;
int n, m, vis[310][310];
char s[100010];
vector<pair<pair<int, int>, pair<int, int> > > res;
inline void add(int sx, int sy, int tx, int ty) {
  res.push_back(make_pair(make_pair(sx, sy), make_pair(tx, ty)));
  vis[tx][ty]++;
}
inline void move(int x, int y, bool t) {
  if (t) {
    if (x != 2)
      add(x, y, 2, y);
    else
      add(x, y, 2, y == 1 ? 2 : 1);
  } else {
    if (x != 1)
      add(x, y, 1, y);
    else
      add(x, y, 1, y == 1 ? 2 : 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%s", s + 1);
      for (int k = strlen(s + 1); k; k--) move(i, j, s[k] == '1');
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 2; j <= m; j++) {
      for (int k = 1; k <= vis[i][j]; k++) add(i, j, i, 1);
      vis[i][j] = 0;
    }
  int tot = res.size();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%s", s + 1);
      for (int k = 1; s[k]; k++) move(i, j, s[k] == '1');
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 2; j <= m; j++)
      for (int k = 1; k <= vis[i][j]; k++) add(i, j, i, 1);
  printf("%d\n", res.size());
  for (int i = 0; i < tot; i++)
    printf("%d %d %d %d\n", res[i].first.first, res[i].first.second,
           res[i].second.first, res[i].second.second);
  for (int i = res.size() - 1; i >= tot; i--)
    printf("%d %d %d %d\n", res[i].second.first, res[i].second.second,
           res[i].first.first, res[i].first.second);
  return 0;
}
