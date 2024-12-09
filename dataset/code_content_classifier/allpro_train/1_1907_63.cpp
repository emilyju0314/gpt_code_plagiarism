#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& p) {
  out << "[";
  for (int i = 0; i < (int)p.size(); ++i) {
    if (i) out << ", ";
    out << p[i];
  }
  return out << "]";
}
template <class A>
ostream& operator<<(ostream& out, const set<A>& p) {
  out << "{";
  int i = 0;
  for (auto e : p) {
    if (i) out << ", ";
    out << e;
    ++i;
  }
  return out << "}";
}
const int INF = (int)2e9 + 1000;
const long long INF64 = (long long)1e18 + 1000;
const int N = (int)1e6 + 1000;
const int MOD = (int)998244353;
const long double PI = acos(-1.);
const long double EPS = 1e-9;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  if (n - 1 > m) {
    cout << "Impossible\n";
    return 0;
  }
  for (int i = 1; i <= n && m; ++i) {
    for (int j = i + 1; j <= n && m; ++j) {
      if (gcd(i, j) == 1) {
        g[i - 1].push_back(j - 1);
        --m;
      }
    }
  }
  if (m > 0) {
    cout << "Impossible\n";
  } else {
    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
      for (auto to : g[i]) {
        cout << i + 1 << ' ' << to + 1 << '\n';
      }
    }
  }
}
