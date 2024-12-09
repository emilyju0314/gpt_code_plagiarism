#include <bits/stdc++.h>
const long long int INF = 1e18;
int n, m, s, t, vis[1010], path[1010], err;
long long int L, d[1010], d2[1010];
int w[1010][1010];
void dijk() {
  int cnt = 0, u;
  long long int mn;
  for (int i = 0; i < n; i++) d[i] = INF;
  d[s] = 0;
  while (cnt < n) {
    mn = INF;
    for (int i = 0; i < n; i++)
      if (vis[i] != 1 && d[i] < mn) {
        mn = d[i];
        u = i;
      }
    vis[u] = 1, cnt++;
    for (int i = 0; i < n; i++)
      if (w[u][i] > 0 && d[i] > d[u] + w[u][i]) d[i] = d[u] + w[u][i];
  }
  return;
}
void dijk2() {
  int cnt = 0, u;
  long long int mn;
  for (int i = 0; i < n; i++) d2[i] = INF, vis[i] = 0;
  d2[s] = 0;
  while (cnt < n) {
    mn = INF;
    for (int i = 0; i < n; i++)
      if (vis[i] != 1 && d2[i] < mn) {
        mn = d2[i];
        u = i;
      }
    vis[u] = 1, cnt++;
    for (int i = 0; i < n; i++) {
      if (w[u][i] > 0 && d2[i] > d2[u] + w[u][i])
        d2[i] = d2[u] + w[u][i], path[i] = u;
      if (w[u][i] == -1 && d2[i] > d2[u] + 1) d2[i] = d2[u] + 1, path[i] = u;
    }
  }
  return;
}
int main() {
  scanf("%d%d%I64d%d%d", &n, &m, &L, &s, &t);
  for (int i = 0; i < m; i++) {
    int u, v, wt;
    scanf("%d%d%d", &u, &v, &wt);
    if (wt != 0)
      w[u][v] = wt, w[v][u] = wt;
    else
      w[u][v] = -1, w[v][u] = -1;
  }
  dijk();
  dijk2();
  if (d[t] < L || d2[t] > L)
    printf("NO");
  else {
    int track = t;
    long long int tot = L;
    while (track != s) {
      int u = track, v = path[track];
      if (w[u][v] == -1) {
        if (tot - d[v] > INF) {
          err = -1;
          break;
        }
        if (tot > d[v])
          w[u][v] = tot - d[v], w[v][u] = tot - d[v];
        else
          w[u][v] = 1, w[v][u] = 1;
      }
      track = path[track];
      tot -= w[u][v];
    }
    if (err == -1)
      printf("NO");
    else {
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (w[i][j] > 0) printf("%d %d %d\n", i, j, w[i][j]);
          if (w[i][j] == -1) printf("%d %d %d\n", i, j, L + 1);
        }
      }
    }
  }
  return 0;
}
