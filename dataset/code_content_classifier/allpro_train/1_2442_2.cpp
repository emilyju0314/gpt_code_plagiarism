#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
  vector<bitset<2001>> dp(1 << n);
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = sum; j >= 0; j--)
      if (dp[i][j] && j % k == 0) dp[i][j / k] = 1;
    for (int add = 0; add < n; ++add) {
      if (i & (1 << add)) continue;
      dp[i | (1 << add)] |= (dp[i] << a[add]);
    }
  }
  vector<int> b(n);
  function<void(int, int)> restore = [&](int mask, int s) {
    if (mask == 0 && s == 0) return;
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i))) continue;
      if (s >= a[i] && dp[mask ^ (1 << i)][s - a[i]]) {
        restore(mask ^ (1 << i), s - a[i]);
        return;
      }
    }
    for (int t = 1; t * s * k <= sum; ++t) {
      if (dp[mask][t * s * k]) {
        for (int i = 0; i < n; ++i) {
          if (mask & (1 << i)) b[i] += t;
        }
        restore(mask, t * s * k);
        return;
      }
    }
  };
  if (dp[(1 << n) - 1][1]) {
    cout << "YES\n";
    restore((1 << n) - 1, 1);
    multiset<pair<int, int>> s;
    for (int i = 0; i < n; ++i) s.insert(make_pair(-b[i], a[i]));
    for (int i = 0; i < n - 1; ++i) {
      auto x = s.begin();
      s.erase(s.begin());
      auto y = s.begin();
      s.erase(s.begin());
      int vx = x->second, vy = y->second, P = -x->first;
      cout << vx << ' ' << vy << '\n';
      int sum = (x->second + y->second);
      int nrd = 0;
      while (sum % k == 0) {
        sum /= k;
        nrd++;
      }
      s.insert(make_pair(-(P - nrd), sum));
    }
  } else {
    cout << "NO\n";
  }
}
