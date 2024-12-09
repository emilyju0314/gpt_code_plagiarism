#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long double PI = 3.14159265358979323846;
const long double eps = 1e-11;
const long long INF = 1.5e18;
const long long inf = 1e9;
const long long M = 998244353;
const string IO[2]{"NO\n", "YES\n"};
const string Io[2]{"No\n", "Yes\n"};
const string io[2]{"no\n", "yes\n"};
const string bads = "-1\n";
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
  out << a.first << ' ' << a.second;
  return out;
}
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& el : a) {
    in >> el;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto& el : a) {
    out << el << ' ';
  }
  return out;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long ssize = n / m;
  long long bsize = (n + m - 1) / m;
  long long cnt = n % m;
  vector<vector<pair<long long, long long> > > el(k);
  long long start = 0, last_start = 0;
  for (long long i = 0; i < k; ++i) {
    start = last_start;
    for (long long j = 0; j < cnt; ++j) {
      el[i].push_back({start, (start + bsize) % n});
      start += bsize;
      start %= n;
      last_start = start;
    }
    for (long long j = 0; j < m - cnt; ++j) {
      el[i].push_back({start, (start + ssize) % n});
      start += ssize;
      start %= n;
    }
  }
  for (long long i = 0; i < k; ++i) {
    for (auto block : el[i]) {
      vector<long long> ans;
      long long i = block.first;
      bool ok = 1;
      while (i != block.second || ok) {
        ok = 0;
        ans.push_back(i++ + 1);
        i %= n;
      }
      cout << ans.size() << ' ' << ans << '\n';
    }
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
