#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265359;
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[n + 3][m + 3];
    vector<vector<pair<long long, long long> > > ans;
    for (long long i = (long long)(1); i <= (long long)(n); i++) {
      for (long long j = (long long)(1); j <= (long long)(m); j++) {
        char x;
        cin >> x;
        a[i][j] = x - '0';
      }
    }
    for (long long i = (long long)(1); i <= (long long)(n - 1); i++) {
      for (long long j = (long long)(1); j <= (long long)(m - 1); j++) {
        if (a[i][j]) {
          ans.push_back({{i, j}, {i + 1, j}, {i, j + 1}});
          a[i][j] = 0;
          a[i + 1][j] = 1 - a[i + 1][j];
          a[i][j + 1] = 1 - a[i][j + 1];
        }
      }
    }
    for (long long i = (long long)(1); i <= (long long)(n - 1); i++) {
      if (a[i][m] && a[i + 1][m]) {
        ans.push_back({{i, m}, {i, m - 1}, {i + 1, m - 1}});
        ans.push_back({{i, m - 1}, {i + 1, m - 1}, {i + 1, m}});
        a[i][m] = a[i + 1][m] = 0;
      } else if (a[i + 1][m]) {
        ans.push_back({{i, m - 1}, {i + 1, m - 1}, {i + 1, m}});
        ans.push_back({{i + 1, m - 1}, {i, m}, {i + 1, m}});
        ans.push_back({{i, m}, {i + 1, m}, {i, m - 1}});
        a[i + 1][m] = 0;
      } else if (a[i][m]) {
        ans.push_back({{i, m - 1}, {i + 1, m - 1}, {i, m}});
        ans.push_back({{i + 1, m - 1}, {i, m}, {i + 1, m}});
        ans.push_back({{i, m}, {i + 1, m}, {i, m - 1}});
        a[i][m] = 0;
      }
    }
    for (long long j = (long long)(1); j <= (long long)(m - 1); j++) {
      if (a[n][j] && a[n][j + 1]) {
        ans.push_back({{n - 1, j}, {n - 1, j + 1}, {n, j}});
        ans.push_back({{n - 1, j}, {n - 1, j + 1}, {n, j + 1}});
        a[n][j] = a[n][j + 1] = 0;
      } else if (a[n][j + 1]) {
        ans.push_back({{n - 1, j}, {n - 1, j + 1}, {n, j + 1}});
        ans.push_back({{n - 1, j}, {n, j}, {n, j + 1}});
        ans.push_back({{n - 1, j + 1}, {n, j + 1}, {n, j}});
        a[n][j + 1] = 0;
      } else if (a[n][j]) {
        ans.push_back({{n - 1, j}, {n - 1, j + 1}, {n, j}});
        ans.push_back({{n - 1, j}, {n, j}, {n, j + 1}});
        ans.push_back({{n - 1, j + 1}, {n, j + 1}, {n, j}});
        a[n][j] = 0;
      }
    }
    cout << ans.size() << "\n";
    for (auto it : ans) {
      for (auto ii : it) {
        cout << ii.first << " " << ii.second << " ";
      }
      cout << "\n";
    }
  }
}
