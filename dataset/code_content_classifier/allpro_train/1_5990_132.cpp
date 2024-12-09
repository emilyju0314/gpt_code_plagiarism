#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > arr(m);
  for (auto &i : arr) cin >> i.first >> i.second;
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  vector<long long> pre(m);
  pre[0] = arr[0].first;
  for (long long i = 1; i < m; ++i) pre[i] = arr[i].first + pre[i - 1];
  long long mx = pre[min(n - 1, m - 1)];
  for (long long i = 0; i < m; ++i) {
    long long st = arr[i].first;
    long long en = arr[i].second;
    long long val = 0;
    long long dn = 0;
    long long l = -1, r = m;
    while (l + 1 < r) {
      long long md = (l + r) / 2;
      if (arr[md].first > en)
        l = md;
      else
        r = md;
    };
    if (r - 1 == -1) {
      val = st + (n - 1) * en;
      mx = max(val, mx);
      continue;
    }
    {
      val += pre[l];
      if (l >= n) continue;
      dn += r;
      if (r - 1 < i) {
        dn++;
        val += arr[i].first;
      }
      long long rem = n - dn;
      val += rem * en;
    };
    mx = max(val, mx);
  }
  cout << mx << '\n';
}
signed main() {
  cin.tie(NULL), ios_base::sync_with_stdio(false), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
