#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, m, x, y, vis[501];
int mp[501][501], inq[501], du[501];
vector<int> q, Son[501];
double Ans, p[501], p_dis[501];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) mp[i][j] = inf;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    mp[x][y] = mp[y][x] = 1;
    Son[x].push_back(y);
    Son[y].push_back(x);
    ++du[x];
    ++du[y];
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (mp[i][j] > mp[i][k] + mp[k][j]) mp[i][j] = mp[i][k] + mp[k][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) vis[j] = 0;
    double Tmp = 0.0;
    for (int j = 1; j <= n; ++j)
      if (!vis[j]) {
        for (int k = 1; k <= n; ++k) p[k] = inq[k] = 0;
        q.clear();
        for (int k = 1; k <= n; ++k) {
          if (mp[i][k] == mp[i][j]) {
            for (auto v : Son[k]) {
              p[v] += 1.0 / n / du[k];
              if (!inq[v]) {
                q.push_back(v);
                inq[v] = 1;
              }
            }
            vis[k] = 1;
          }
        }
        double tmp = 0.0;
        for (int k = 1; k <= n; ++k) {
          double sum = 0.0;
          for (auto v : q) p_dis[mp[k][v]] = max(p_dis[mp[k][v]], p[v]);
          for (auto v : q) {
            sum += p_dis[mp[k][v]];
            p_dis[mp[k][v]] = 0.0;
          }
          tmp = max(tmp, sum);
        }
        Tmp += max(1.0 / n, tmp);
      }
    if (Tmp > Ans) Ans = Tmp;
  }
  printf("%.9lf\n", Ans);
  return 0;
}
