#include <bits/stdc++.h>
using namespace std;
void solve() {
  char s[3][3];
  for (long long i = 0; i < 3; ++i)
    for (long long j = 0; j < 3; ++j) cin >> s[i][j];
  for (long long i = 0; i < 3; ++i)
    for (long long j = 0; j < 3; ++j)
      if (s[i][j] != s[2 - i][2 - j]) {
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
