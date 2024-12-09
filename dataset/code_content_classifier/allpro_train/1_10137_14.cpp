#include <bits/stdc++.h>
#pragma GCC optimize 03
using namespace std;
const int N = 1e6 + 1;
set<vector<int> > s;
vector<int> v[N];
int top[N];
vector<vector<int> > qt;
set<int> H;
int dp[289][31][1201];
int get(int a) {
  for (int i = 0; i < 289; ++i)
    if (qt[i] == v[a]) return i;
}
int main() {
  int i, j, k, n, l;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (i = 1; i < N; ++i) {
    v[i].resize(7);
    for (j = 0; j < 7; ++j) v[i][j] = 1;
  }
  for (i = 2; i < N; ++i)
    if (top[i] == 0) {
      for (j = 1; i * j < N; ++j) {
        int x = j;
        int p = 2;
        while (x % i == 0) {
          x /= i;
          ++p;
        }
        v[i * j][top[i * j]] = p;
        ++top[i * j];
      }
    }
  l = 0;
  for (i = 1; i < N; ++i) {
    sort(v[i].begin(), v[i].end());
    l = max(l, (int)v[i].size());
    if (v[i].size() > 0) {
      s.insert(v[i]);
    }
  }
  for (set<vector<int> >::iterator it = s.begin(); it != s.end(); ++it)
    qt.push_back((*it));
  for (i = 0; i < qt.size(); ++i)
    for (j = 0; j <= 30; ++j)
      for (l = 0; l <= 1200; ++l) dp[i][j][l] = 999;
  for (int y = 0; y < qt.size(); ++y) {
    vector<int> T;
    for (j = 0; j < 7; ++j) T.push_back(qt[y][j]);
    for (j = 0; T.size() < 30; ++j) T.push_back(1);
    dp[y][0][1] = 0;
    for (i = 0; i < 30; ++i)
      for (j = 1; j <= 1200; ++j)
        if (dp[y][i][j] < 999)
          for (l = max(1, T[i] - 30);
               j * l <= 1200 && l <= min(1200, T[i] + 30); ++l)
            dp[y][i + 1][j * l] =
                min(dp[y][i + 1][j * l], dp[y][i][j] + abs(T[i] - l));
  }
  cin >> n;
  for (i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    int p1 = get(a), g1 = get(b);
    int ans = 9000;
    for (j = 1; j <= 1200; ++j) ans = min(ans, dp[p1][30][j] + dp[g1][30][j]);
    cout << ans << "\n";
  }
}
