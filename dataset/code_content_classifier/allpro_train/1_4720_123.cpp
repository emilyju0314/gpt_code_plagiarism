#include <bits/stdc++.h>
using namespace std;
int piao[107][107];
int n, m;
int winnum[107];
int win;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) scanf("%d", piao[i] + j);
  for (int i = 0; i < m; i++) {
    int maxn = -(2147483647 - 214748 + 3647);
    for (int j = 0; j < n; j++)
      if (piao[i][j] > maxn) maxn = piao[i][j];
    for (int j = 0; j < n; j++)
      if (piao[i][j] == maxn) {
        winnum[j + 1]++;
        break;
      }
  }
  int maxx = -(2147483647 - 214748 + 3647);
  for (int i = 1; i <= n; i++) maxx = max(maxx, winnum[i]);
  for (int i = 1; i <= n; i++)
    if (winnum[i] == maxx) return 0 * printf("%d\n", i);
}
