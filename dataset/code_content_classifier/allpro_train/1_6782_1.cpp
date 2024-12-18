#include <bits/stdc++.h>
using namespace std;
int n;
int a[200], b[200];
int g[10][10], d[10];
int pl[200], pr[200], p0;
bool chk[200];
void euler(int v) {
  for (int i = 0; i <= 6; ++i)
    if (g[v][i] > 0) {
      g[v][i]--;
      g[i][v]--;
      euler(i);
      p0++;
      pl[p0] = v;
      pr[p0] = i;
    }
}
int main() {
  scanf("%d", &n);
  memset(g, 0, sizeof(g));
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    g[a[i]][b[i]]++;
    g[b[i]][a[i]]++;
    d[a[i]]++;
    d[b[i]]++;
  }
  int s;
  for (int i = 0; i <= 6; ++i)
    if (d[i] > 0) s = i;
  int tmp = 0;
  for (int i = 0; i <= 6; ++i)
    if (d[i] & 1) s = i, tmp++;
  if (tmp != 0 && tmp != 2) {
    printf("No solution\n");
    return 0;
  }
  p0 = 0;
  euler(s);
  if (p0 < n) {
    printf("No solution\n");
    return 0;
  }
  memset(chk, 0, sizeof(chk));
  for (int i = n; i > 0; --i)
    for (int j = 1; j <= n; ++j)
      if (!chk[j])
        if (pl[i] == a[j] && pr[i] == b[j]) {
          printf("%d +\n", j);
          chk[j] = true;
          break;
        } else if (pl[i] == b[j] && pr[i] == a[j]) {
          printf("%d -\n", j);
          chk[j] = true;
          break;
        }
  return 0;
}
