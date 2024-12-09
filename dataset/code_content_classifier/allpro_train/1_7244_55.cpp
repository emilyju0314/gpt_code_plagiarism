#include <bits/stdc++.h>
using namespace std;
int static_init = []() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
  return 0;
}();
constexpr int N = 2e3;
int n, ans;
int8_t a[N + 1];
int16_t b[N + 1];
int main() {
  cin >> n;
  for (int ai, i = 1; i <= n; i++) {
    cin >> ai;
    a[i] = ai;
    b[i] = b[i - 1];
    if (a[i] == 1)
      ans = max(ans, (int)++b[i]);
    else
      ans++;
  }
  for (int j = n; j > 0; j--) {
    int dp[2]{}, m = (n - j) - (b[n] - b[j]);
    for (int i = j; i > 0; i--) {
      if (a[i] == 1)
        dp[1] = max(dp[1], ++dp[0]);
      else
        dp[1]++;
      ans = max(ans, b[i - 1] + dp[1] + m);
    }
  }
  cout << ans << endl;
  return 0;
}
