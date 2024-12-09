#include <bits/stdc++.h>
using namespace std;
int dp[550005];
int main() {
  int n, d, c, i, j, x, flog;
  scanf("%d %d", &n, &d);
  dp[0] = 1;
  for (i = 0; i < n; i++) {
    scanf("%d", &c);
    for (j = 500000; j >= c; j--) {
      dp[j] |= dp[j - c];
    }
  }
  int day = 0;
  x = 0;
  while (1) {
    flog = 0;
    for (j = x + d; j > x; j--) {
      if (dp[j]) {
        flog = 1;
        day++;
        x = j;
        break;
      }
    }
    if (!flog) break;
  }
  printf("%d %d\n", x, day);
}
