#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000 + 10;
int n, k, a[MAX_N], dp[MAX_N];
bool check(int x) {
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; ~j; j--)
      if (abs(a[i] - a[j]) <= 1LL * (i - j) * x) dp[i] = max(dp[i], dp[j] + 1);
    if (n - dp[i] <= k) return true;
  }
  return false;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int L = -1, R = 2e9 + 10;
  while (L + 1 < R) {
    int mid = (1LL * L + R) >> 1;
    check(mid) ? R = mid : L = mid;
  }
  cout << R << endl;
  return 0;
}
