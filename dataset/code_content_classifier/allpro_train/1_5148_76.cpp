#include <bits/stdc++.h>
using namespace std;
int L[305], C[305];
vector<int> vc[305];
int dp[1 << 10];
int main() {
  int i, j, k, tmp;
  int n, ans;
  int si, sj, mask;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &L[i]);
    j = L[i];
    for (k = 2; k * k <= j; ++k) {
      if (j % k == 0) {
        vc[i].push_back(k);
        while (j % k == 0) j /= k;
      }
    }
    if (j > 1) vc[i].push_back(j);
  }
  for (i = 0; i < n; ++i) scanf("%d", &C[i]);
  ans = 0x3f3f3f3f;
  for (i = 0; i < n; ++i) {
    si = vc[i].size();
    memset(dp, 0x3f, sizeof(dp));
    dp[(1 << si) - 1] = C[i];
    for (j = 0; j < i; ++j) {
      mask = 0;
      sj = vc[j].size();
      for (int ii = 0; ii < si; ++ii) {
        for (int jj = 0; jj < sj; ++jj) {
          if (vc[i][ii] == vc[j][jj]) {
            mask |= (1 << ii);
            break;
          }
        }
      }
      for (k = 0; k < (1 << si); ++k) {
        if (dp[k] != 0x3f3f3f3f) {
          tmp = k & mask;
          dp[tmp] = min(dp[tmp], dp[k] + C[j]);
        }
      }
    }
    ans = min(ans, dp[0]);
  }
  if (ans == 0x3f3f3f3f)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}
