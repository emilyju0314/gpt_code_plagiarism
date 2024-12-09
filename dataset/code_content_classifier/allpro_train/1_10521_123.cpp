#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  const int N = 5e5 + 5;
  vector<int> p(N + 5);
  for (long long i = 3; i <= N; i += 2)
    if (!p[i])
      for (long long j = i * i; j <= N; j += 2 * i) p[j] = i;
  for (int i = 4; i <= N; i += 2) p[i] = 2;
  vector<vector<int>> pr(N + 5);
  for (auto i : a) {
    if (i == 1 || !pr[i].empty()) continue;
    int x = i;
    while (p[x]) {
      int d = p[x];
      pr[i].push_back(d);
      while (x % d == 0) x /= d;
    }
    if (x > 1) pr[i].push_back(x);
  }
  long long cur = 0;
  int cnt = 0;
  vector<int> mp(N + 5);
  for (int i; q--;) {
    cin >> i;
    --i;
    if (a[i] > 0) {
      auto &vec = pr[a[i]];
      int ans = cnt, sz = vec.size();
      for (int m = 1; m < 1 << sz; ++m) {
        int f = 1, sg = 1;
        for (int j = 0; j < sz; ++j)
          if (m >> j & 1) f *= vec[j], sg = -sg;
        ans += mp[f] * sg;
      }
      cur += ans;
      ++cnt;
      for (int m = 1; m < 1 << sz; ++m) {
        int f = 1;
        for (int j = 0; j < sz; ++j)
          if (m >> j & 1) f *= vec[j];
        ++mp[f];
      }
    } else {
      --cnt;
      auto &vec = pr[-a[i]];
      int ans = cnt, sz = vec.size();
      for (int m = 1; m < 1 << sz; ++m) {
        int f = 1;
        for (int j = 0; j < sz; ++j)
          if (m >> j & 1) f *= vec[j];
        --mp[f];
      }
      for (int m = 1; m < 1 << sz; ++m) {
        int f = 1, sg = 1;
        for (int j = 0; j < sz; ++j)
          if (m >> j & 1) f *= vec[j], sg = -sg;
        ans += mp[f] * sg;
      }
      cur -= ans;
    }
    a[i] *= -1;
    cout << cur << "\n";
  }
  return 0;
}
