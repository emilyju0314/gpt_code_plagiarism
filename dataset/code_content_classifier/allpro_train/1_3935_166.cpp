#include <bits/stdc++.h>
using namespace std;
int n, l, top, tmp, m, c[12];
bool opt[12][11][1 << 13];
void Search(int t, int v, int sum, int u, int i) {
  if (v < 0) return;
  if (sum >= v) opt[t][sum - v][u | (1 << t)] = 1;
  if (i >= t) return;
  if (((u >> i) & 1) == 1 && c[i] + 1 < c[t])
    Search(t, v - c[i], sum, u ^ (1 << i), i + 1);
  Search(t, v, sum, u, i + 1);
}
bool Check() {
  for (int i = 0; i < l; i++)
    if (c[i] == 2) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  l = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    if (tmp > 1) c[l++] = tmp;
  }
  if (l > n / 2) {
    printf("NO\n");
    return 0;
  }
  if (l == 0) {
    if (n > 1)
      printf("NO\n");
    else
      printf("YES\n");
    return 0;
  }
  sort(c, c + l);
  top = n - l - c[0] + 1;
  opt[0][top][1] = 1;
  for (int i = 1; i < l; i++)
    for (int t = 0; t <= top; t++) {
      m = 1 << i;
      for (int u = 0; u < m; u++)
        if (opt[i - 1][t][u]) Search(i, c[i] - 1, t, u, 0);
    }
  if (opt[l - 1][0][1 << (l - 1)] && Check())
    printf("YES\n");
  else
    printf("NO\n");
}
