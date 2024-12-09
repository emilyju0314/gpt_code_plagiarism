#include <bits/stdc++.h>
using namespace std;
void solve(long long _case) {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n), b(n);
  vector<long long> ma(n), mb(n);
  for (long long i{}; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<long long> pia(n), pib(n);
  sort(a.begin(), a.end());
  for (long long i{}; i < n; ++i) {
    pia[a[i].second] = i;
  }
  for (long long i{}; i < n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  for (long long i{}; i < n; ++i) {
    pib[b[i].second] = i;
  }
  long long la = n - 1, lb = n - 1, minb = b[pib[a[la].second]].first,
            mina = a[pia[b[lb].second]].first;
  ;
  ;
  bool change = true;
  while (change) {
    ;
    change = false;
    while (la && mina <= a[la].first) {
      minb = min(minb, b[pib[a[la].second]].first);
      change = true;
      --la;
    }
    while (lb && minb <= b[lb].first) {
      mina = min(mina, a[pia[b[lb].second]].first);
      change = true;
      --lb;
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  };
  vector<long long> win(n);
  for (long long i{la + 1}; i < n; ++i) {
    win[a[i].second] = true;
  }
  for (long long i{lb + 1}; i < n; ++i) {
    win[b[i].second] = true;
  }
  for (long long i{}; i < n; ++i) {
    cout << win[i];
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long _case{1}; _case <= t; ++_case) {
    solve(_case);
  }
  return 0;
}
