#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, M, xc, yc, huan;
int vis[maxn], a[maxn], u[maxn];
vector<pair<int, int> > f[maxn];
void dfs(int s, int fa, int depth) {
  vis[s] = depth;
  int cs;
  for (int i = 0; i < f[s].size(); i++)
    if (f[s][i].first != fa) {
      cs = f[s][i].first;
      if ((vis[cs] != 2139062143) && (vis[cs] != vis[s] + f[s][i].second)) {
        huan = abs(vis[cs] - (vis[s] + f[s][i].second));
        return;
      }
      if (vis[cs] == 2139062143) dfs(cs, s, depth + f[s][i].second);
    }
}
bool check(int color) {
  memset(a, 0, sizeof(a));
  pair<int, int> cs;
  int rc, fc, tt;
  for (int i = 1; i <= N; i++)
    if (a[i] == 0) {
      rc = 1, fc = 1, u[rc] = i, a[i] = 1;
      while (rc <= fc) {
        for (int j = 0; j < f[u[rc]].size(); j++) {
          cs = f[u[rc]][j];
          if (a[cs.first] == 0) {
            a[cs.first] = (a[u[rc]] + cs.second + color - 1) % color + 1;
            ++fc, u[fc] = cs.first;
          } else {
            tt = (a[u[rc]] + cs.second + color - 1) % color + 1;
            if (tt != a[cs.first]) return false;
          }
        }
        ++rc;
      }
    }
  return true;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d %d", &xc, &yc);
    f[xc].push_back(make_pair(yc, 1));
    f[yc].push_back(make_pair(xc, -1));
  }
  huan = -1;
  memset(vis, 127, sizeof(vis));
  for (int i = 1; i <= N; i++)
    if (vis[i] == 2139062143) {
      dfs(i, 0, 1);
      if (huan != -1) break;
    }
  if (huan == -1)
    printf("%d\n", N);
  else {
    for (int i = huan; i >= 1; i--)
      if ((huan % i == 0) && (check(i))) {
        printf("%d\n", i);
        break;
      }
  }
  return 0;
}
