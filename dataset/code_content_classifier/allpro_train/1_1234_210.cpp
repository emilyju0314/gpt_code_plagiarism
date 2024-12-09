#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
const long double pi = 3.141592653589793238;
long long MOD = 1000000007;
const long long N = 5e5 + 10;
vector<long long> ans;
long long a, b, c, d;
bool make(long long a, long long b, long long c, long long d) {
  deque<long long> v;
  while (a > 0 && b > 0) {
    v.push_back(0);
    a--;
    v.push_back(1);
    b--;
  }
  if (a > 1) return 0;
  if (a == 1 && (c > 0 || d > 0)) return 0;
  if (a == 1) {
    v.push_back(0);
    a--;
  }
  while (b > 0 && c > 0) {
    v.push_back(2);
    c--;
    v.push_back(1);
    b--;
  }
  if (b >= 1) return 0;
  while (c > 0 && d > 0) {
    v.push_back(2);
    c--;
    v.push_back(3);
    d--;
  }
  if (c > 1) return 0;
  if (c == 1) v.push_back(2);
  if (d > 0) return 0;
  for (auto i : v) ans.push_back(i);
  return 1;
}
void solve() {
  cin >> a >> b >> c >> d;
  if (a > 0) {
    if (make(a, b, c, d)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i << " ";
      cout << '\n';
      return;
    }
    ans.clear();
    ans.push_back(1);
    b--;
    if (b >= 0 && make(a, b, c, d)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i << " ";
      cout << '\n';
      return;
    }
  } else if (b > 0) {
    if (make(b, c, d, 0)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i + 1 << " ";
      cout << '\n';
      return;
    }
    ans.clear();
    ans.push_back(1);
    c--;
    if (c >= 0 && make(b, c, d, 0)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i + 1 << " ";
      cout << '\n';
      return;
    }
  } else if (c > 0) {
    if (make(c, d, 0, 0)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i + 2 << " ";
      cout << '\n';
      return;
    }
    ans.clear();
    ans.push_back(1);
    d--;
    if (d >= 0 && make(c, d, 0, 0)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i + 2 << " ";
      cout << '\n';
      return;
    }
  } else if (d > 0) {
    if (make(d, 0, 0, 0)) {
      cout << "YES" << '\n';
      for (auto i : ans) cout << i + 3 << " ";
      cout << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
