#include <bits/stdc++.h>
#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui = unsigned int;
ll const mod = 1e9 + 7;
auto mt = mt19937(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int>> v;
  while (q--) {
    int t;
    cin >> t;
    if (t == 3) {
      int r, c, x;
      cin >> r >> c >> x;
      --r, --c;
      v.push_back({r, c, x});
    } else if (t == 1) {
      int r;
      cin >> r;
      --r;
      v.push_back({-1, r, r});
    } else {
      int c;
      cin >> c;
      --c;
      v.push_back({-2, c, c});
    }
  }
  vector<vector<int>> xx(n, vector<int>(m, 0));
  for (int i = v.size() - 1; i >= 0; i--) {
    auto& [a, b, c] = v[i];
    if (a >= 0) {
      xx[a][b] = c;
    } else if (a == -1) {
      int last = xx[b][m - 1];
      for (int ii = m - 1; ii > 0; ii--) {
        xx[b][ii] = xx[b][ii - 1];
      }
      xx[b][0] = last;
    } else {
      int last = xx[n - 1][b];
      for (int ii = n - 1; ii > 0; ii--) {
        xx[ii][b] = xx[ii - 1][b];
      }
      xx[0][b] = last;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << xx[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
