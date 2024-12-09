#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int dp[maxn], a[maxn], num[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  memset(dp, -1, sizeof(dp));
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      if (dp[i + 1] != -1) {
        int t = num[i + 1];
        for (int j = t; j > i; j--)
          if (a[i] > a[j]) {
            dp[i] = j - i - 1;
            num[i] = j;
            break;
          }
      }
    } else if (a[i] == a[i + 1]) {
      if (dp[i + 1] != -1) dp[i] = dp[i + 1] + 1;
      num[i] = num[i + 1];
    } else {
      for (int j = n - 1; j > i; j--)
        if (a[i] > a[j]) {
          dp[i] = j - i - 1;
          num[i] = j;
          break;
        }
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", dp[i]);
  return 0;
}
