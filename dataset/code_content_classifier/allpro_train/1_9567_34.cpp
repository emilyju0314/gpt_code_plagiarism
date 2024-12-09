#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = N * N;
const int INF = 1e9 + 5;
int d[N][N], cnt[N], n, m, x[M], y[M], w[M];
int main() {
  int fst = 0;
  scanf("%d%d", &n, &m);
  memset(d, 0x3F, sizeof(d));
  for (int i = (0); i < (m); i++) {
    scanf("%d%d%d", x + i, y + i, w + i);
    x[i]--, y[i]--;
    d[x[i]][y[i]] = d[y[i]][x[i]] = w[i];
  }
  for (int i = (0); i < (n); i++) d[i][i] = 0;
  for (int k = (0); k < (n); k++)
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (n); j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int s = (0); s < (n); s++) {
    for (int i = (0); i < (n); i++) cnt[i] = 0;
    for (int i = (0); i < (m); i++) {
      if (abs(d[s][x[i]] - d[s][y[i]]) != w[i]) continue;
      if (d[s][x[i]] < d[s][y[i]])
        cnt[y[i]]++;
      else
        cnt[x[i]]++;
    }
    for (int i = (s + 1); i < (n); i++) {
      int ans = 0;
      if (d[s][i] > INF) {
        if (fst++) printf(" ");
        printf("0");
      } else {
        for (int j = (0); j < (n); j++)
          if (d[s][j] + d[j][i] == d[s][i]) ans += cnt[j];
        if (fst++) printf(" ");
        printf("%d", ans);
      }
    }
  }
  puts("");
  return 0;
}
