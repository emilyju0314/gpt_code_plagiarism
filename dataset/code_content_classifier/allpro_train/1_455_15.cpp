#include <bits/stdc++.h>
using namespace std;
const int maxC = 2000000000;
int n, m, r, max_change;
int a[65][65][65], dis[65][65][65];
pair<int, pair<int, int> > b[100005];
int main() {
  if (0) {
    freopen("a.inp", "r", stdin);
  };
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) scanf("%d", &a[i][j][k]);
  for (int i = 0; i < r; i++) {
    scanf("%d%d%d", &b[i].first, &b[i].second.first, &b[i].second.second);
    if (b[i].second.second > max_change) max_change = b[i].second.second;
  }
  if (max_change > 60) max_change = 60;
  for (int x = 0; x < m; x++)
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (a[x][i][k] + a[x][k][j] < a[x][i][j])
            a[x][i][j] = a[x][i][k] + a[x][k][j];
  for (int x = 0; x <= max_change; x++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) dis[x][i][j] = maxC;
  for (int x = 0; x < m; x++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) dis[0][i][j] = min(dis[0][i][j], a[x][i][j]);
  for (int x = 1; x <= max_change; x++)
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dis[x][i][j] = min(dis[x][i][j], dis[x - 1][i][k] + dis[0][k][j]);
  for (int i = 0; i < r; i++) {
    if (b[i].second.second > max_change) b[i].second.second = max_change;
    printf("%d\n",
           dis[b[i].second.second][b[i].first - 1][b[i].second.first - 1]);
  }
}
