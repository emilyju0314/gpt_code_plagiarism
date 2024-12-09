#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m, k;
char s1[25], s2[25];
int x[N], y[N], q1[N], q2[N];
int mn[1 << 20 | 5][22], p[25];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s1 + 1, s2 + 1);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = (int)(1); i <= (int)(k); i++) p[i] = i;
  for (int i = (int)(n); i >= (int)(0); i--) {
    for (int j = (int)(1); j <= (int)(k); j++)
      if (s1[j] == '1') q1[i] |= 1 << (p[j] - 1);
    for (int j = (int)(1); j <= (int)(k); j++)
      if (s2[j] == '1') q2[i] |= 1 << (p[j] - 1);
    swap(p[x[i]], p[y[i]]);
  }
  memset(mn, 30, sizeof(mn));
  for (int i = (int)(0); i <= (int)(n); i++)
    mn[q1[i]][0] = min(mn[q1[i]][0], i);
  int ans = k + 1, al = 0, ar = 0;
  for (int i = (int)(0); i <= (int)(k); i++) {
    for (int j = (int)(0); j <= (int)((1 << k) - 1); j++)
      if (mn[j][i] <= n + 1)
        for (int p = (int)(0); p <= (int)(k - 1); p++)
          mn[j ^ (1 << p)][i + 1] = min(mn[j ^ (1 << p)][i + 1], mn[j][i]);
    for (int j = (int)(0); j <= (int)(n); j++)
      if (mn[q2[j]][i] <= j - m) {
        ans = k - i, al = mn[q2[j]][i], ar = j;
        break;
      }
    if (ans != k + 1) break;
  }
  printf("%d\n%d %d\n", ans, al + 1, ar);
}
