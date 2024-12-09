#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
const long long MOD = 1e9 + 7;
const long long MB = 20;
bool cmp(const pair<long long, long long>& one,
         const pair<long long, long long>& two) {
  if (one.first + one.second == two.first + two.second)
    return one.first < two.first;
  return one.first + one.second < two.first + two.second;
}
void go() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i < n; i++) {
    long long x, f;
    cin >> x >> f;
    x--;
    if (f)
      a[x].first++;
    else
      a[x].second++;
  }
  sort(a.rbegin(), a.rend(), cmp);
  long long now = INF;
  long long ans1 = 0, ans2 = 0;
  map<pair<long long, long long>, long long> mp;
  for (long long i = 0; i < n && now;) {
    if (now > a[i].first + a[i].second && mp.empty())
      now = a[i].first + a[i].second;
    while (i < n && a[i].first + a[i].second >= now) {
      mp[a[i]]++;
      i++;
    }
    auto p = *mp.rbegin();
    mp[p.first]--;
    if (!mp[p.first]) mp.erase(p.first);
    ans1 += now;
    ans2 += min(p.first.first, now);
    now--;
  }
  cout << ans1 << " " << ans2 << '\n';
}
void solve() {
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    go();
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(12);
  solve();
}
