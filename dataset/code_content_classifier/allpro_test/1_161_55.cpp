#include <bits/stdc++.h>
using namespace std;
long long n;
pair<pair<long long, long long>, long long> p[1010];
bool st[1010];
bool cmp(pair<pair<long long, long long>, long long> w,
         pair<pair<long long, long long>, long long> u) {
  pair<long long, long long> a = w.first, b = u.first;
  if ((a.second - a.first) != (b.second - b.first))
    return (a.second - a.first) < (b.second - b.first);
  return a.first < b.first;
}
long long ans[1010];
pair<long long, long long> v[1010];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> p[i].first.first >> p[i].first.second, p[i].second = i, st[i] = 0;
  for (long long i = 1; i <= n; i++) v[i] = p[i].first;
  sort(p + 1, p + 1 + n, cmp);
  for (long long i = 1; i <= n; i++) {
    for (long long j = p[i].first.first; j <= p[i].first.second; j++) {
      if (!st[j]) {
        ans[p[i].second] = j;
        st[j] = true;
        break;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << v[i].first << ' ' << v[i].second << ' ' << ans[i] << endl;
  }
  cout << endl;
}
signed main() {
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
