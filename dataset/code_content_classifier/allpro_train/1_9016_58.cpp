#include <bits/stdc++.h>
using namespace std;
const long long maxn = 333;
long long n, m, r;
multiset<long long> s;
pair<long long, long long> p[maxn];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.second >= 0 and b.second >= 0)
    return a.first < b.first;
  else if (a.second < 0 and b.second < 0)
    return a.first + a.second > b.first + b.second;
  return a.second > b.second;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r;
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first = max(p[i].first, -p[i].second);
  }
  sort(p, p + n, cmp);
  for (long long i = 0; i < n; i++)
    if (p[i].first <= r) {
      r += p[i].second;
      s.insert(p[i].second);
    } else if (p[i].second >= 0 and s.size() and *s.begin() < p[i].second) {
      long long t = *s.begin();
      s.erase(s.find(t));
      r -= t;
      r += p[i].second;
      s.insert(p[i].second);
    }
  if (s.size() == n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
