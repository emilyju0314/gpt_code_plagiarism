#include <bits/stdc++.h>
using namespace std;
int dp[1000007];
int main() {
  int n;
  scanf("%d", &n);
  dp[1] = dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    int im = (i - 1) / 2;
    if (2 * im == (i - 1) && im % 2 == 0)
      dp[i] = dp[im];
    else if ((2 * im + 1) == (i - 1))
      dp[i] = dp[im] && dp[im + 1];
  }
  printf("%d\n", dp[n]);
}
