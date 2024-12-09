#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e3 + 5;
long long n, dp[2][MAX], a[MAX], b[MAX];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = n - 1; i >= 0; i--) {
    for (int mn = n - 1; mn >= 0; mn--) {
      if (a[i] <= b[mn]) {
        dp[i & 1][mn] = b[mn] - a[i] + dp[(i + 1) & 1][mn];
      } else if (i == n - 1) {
        dp[i & 1][mn] = 0;
      } else {
        long long w1 = max(0LL, a[i] - b[mn]) + dp[(i + 1) & 1][mn];
        long long w2 = dp[i & 1][mn + 1];
        dp[i & 1][mn] = min(w1, w2);
      }
    }
  }
  cout << dp[0][0] << endl;
}
