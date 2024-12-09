#include <bits/stdc++.h>
using namespace std;
const int N = 4003;
int t[N], d[N];
int DAY = 24 * 60 * 60 + 1;
int DP[N][N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (n == 0) {
    printf("%d\n", 60 * 60 * 24);
    return 0;
  }
  for (int i = 0; i < n; i++) scanf("%d %d", &t[i], &d[i]);
  int f = 1;
  for (int i = 0; i < n; i++) {
    f = DP[i][0] = max(f, t[i]) + d[i];
  }
  for (int k = 0; k <= n; k++) DP[0][k] = 1;
  DP[0][0] = t[0] + d[0];
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i + 1; j++) {
      int r = max(t[i], DP[i - 1][j]) + d[i];
      r = min(r, DP[i - 1][j - 1]);
      DP[i][j] = r;
    }
  }
  int RES = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i + 1; j++) {
      int nxt = DAY;
      if (i + k - j + 1 < n) nxt = t[i + k - j + 1];
      RES = max(RES, nxt - DP[i][j]);
    }
  }
  printf("%d\n", RES);
}
