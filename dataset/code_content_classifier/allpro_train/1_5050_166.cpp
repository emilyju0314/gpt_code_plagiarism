#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto factorize = [](int n) {
    vector<int> res;
    int d = 2;
    while (d * d <= n) {
      while (n % d == 0) {
        n /= d;
        res.push_back(d);
      }
      d++;
    }
    if (n > 1) {
      res.push_back(n);
    }
    return res;
  };
  const int MAX = 1e5;
  vector<int> dp(MAX + 1);
  for (int i = 0; i < n; ++i) {
    vector<int> factors = factorize(a[i]);
    int mx = 0;
    for (int f : factors) {
      mx = max(mx, dp[f]);
    }
    for (int f : factors) {
      dp[f] = mx + 1;
    }
  }
  cout << max(1, *max_element(dp.begin(), dp.end())) << '\n';
  return 0;
}
