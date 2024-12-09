#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
const int N = 2e5 + 10;
long long l, r, n, m;
vector<int> v[N];
set<pair<int, int>> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      v[j].push_back(i);
    }
  }
  cin >> n >> m >> l >> r;
  long long j1 = m, j2 = m;
  for (long long i = 1; i <= n; i++) {
    long long x1 = i;
    long long L = (l + x1 - 1) / x1;
    long long R = r / x1;
    while (L <= j1) {
      for (auto p : v[j1]) {
        s.insert({p, j1});
      }
      j1--;
    }
    while (R < j2) {
      for (auto p : v[j2]) {
        s.erase({p, j2});
      }
      j2--;
    }
    bool ok = 0;
    for (auto b : v[x1]) {
      auto it = s.upper_bound({b + 1, 0});
      if (it == s.end()) continue;
      long long y1 = (*it).second;
      long long a = (*it).first;
      long long x2 = x1 / b * a;
      long long y2 = y1 / a * b;
      if (x2 <= n) {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) cout << "-1\n";
  }
}
