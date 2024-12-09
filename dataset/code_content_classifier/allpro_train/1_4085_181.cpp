#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int dp[N][N + 1] = {0};
int a[N];
int pre_compute_dp(int l, int r) {
  assert(l < r);
  if (dp[l][r] != 0) {
    return dp[l][r];
  }
  if ((l + 1) == r) {
    return dp[l][r] = a[l];
  }
  dp[l][r] = -1;
  for (int mid = l + 1; mid < r; mid++) {
    int lf = pre_compute_dp(l, mid);
    int rg = pre_compute_dp(mid, r);
    if (lf > 0 && lf == rg) {
      return dp[l][r] = lf + 1;
    }
  }
  return dp[l][r];
}
vector<int> dp2(N + 1, 1000000000);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pre_compute_dp(0, n);
  dp2[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (dp[i][j] > 0) {
        dp2[j] = min(dp2[j], dp2[i] + 1);
      }
    }
  }
  cout << dp2[n] << "\n";
}
