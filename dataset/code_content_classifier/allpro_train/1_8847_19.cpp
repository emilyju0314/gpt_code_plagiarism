#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
void solve(int test) {
  int n, k;
  cin >> n >> k;
  vector<pair<pair<int, int>, int>> v(n);
  int i, j, l;
  for (i = (0); i < (n); ++i) cin >> v[i].first.first >> v[i].first.second;
  for (i = (0); i < (n); ++i)
    if (v[i].first.first == 0 && v[i].first.second == 0) break;
  if (i == n) throw 0;
  if (i != 0) swap(v[0], v[i]);
  for (i = (1); i < (n); ++i) {
    v[i].second = gcd(abs(v[i].first.first), abs(v[i].first.second));
    v[i].first.first /= v[i].second;
    v[i].first.second /= v[i].second;
  }
  sort(v.begin() + 1, v.end());
  int prev = 1;
  vector<double> all(1, 0.0), neg;
  for (i = (2); i < (n + 1); ++i)
    if (i == n || v[prev].first != v[i].first) {
      long long x = v[prev].first.first;
      long long y = v[prev].first.second;
      double len = sqrt(x * x + y * y + 0.0);
      vector<double> w;
      for (j = (prev); j < (i); ++j) w.push_back(len * v[j].second);
      reverse((w).begin(), (w).end());
      int mid = min((k + 1) / 2, int((w).size()));
      for (j = (0); j < (mid); ++j) all.push_back(w[j] * (k - 1 - 2 * j));
      for (j = (mid); j < (int((w).size())); ++j) neg.push_back(w[j]);
      prev = i;
    }
  sort((all).begin(), (all).end());
  sort((neg).begin(), (neg).end());
  if (int((all).size()) < k) {
    int cnt = k - int((all).size());
    int mid = (k + 1) / 2;
    for (i = (0); i < (cnt); ++i)
      all.push_back(neg[i] * (k - 1 - 2 * (mid + cnt - 1 - i)));
    sort((all).begin(), (all).end());
  }
  reverse((all).begin(), (all).end());
  double res = 0;
  for (i = (0); i < (k); ++i) res += all[i];
  cout.precision(11);
  cout << res << endl;
}
int main() {
  int T = 1, t;
  for (t = (0); t < (T); ++t) solve(t);
  return 0;
}
