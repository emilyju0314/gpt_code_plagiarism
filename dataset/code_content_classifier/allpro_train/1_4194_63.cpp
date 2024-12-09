#include <bits/stdc++.h>
using namespace std;
long int dp[1000001], ar[1000001];
int main() {
  long int n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (i = 1; i <= n; i++) {
    dp[i] = 2;
    for (j = ar[i]; j < i; j++) {
      dp[i] = (dp[i] % 1000000007 + dp[j] % 1000000007) % 1000000007;
    }
  }
  long int ans = 0;
  for (i = 1; i <= n; i++) {
    ans = (ans % 1000000007 + dp[i] % 1000000007) % 1000000007;
  }
  cout << ans;
  return 0;
}
