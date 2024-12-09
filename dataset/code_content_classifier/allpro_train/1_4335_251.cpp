#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    base = (base * base);
    exp /= 2;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  long long *a = new long long[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long *dp = new long long[n];
  dp[0] = 1;
  for (long long i = 1; i < n; i++) {
    if (2 * a[i - 1] >= a[i]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
  }
  long long mx = -1e18;
  for (long long i = 0; i < n; i++) {
    mx = max(mx, dp[i]);
  }
  cout << mx << "\n";
  return 0;
}
