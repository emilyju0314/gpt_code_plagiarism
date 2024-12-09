#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  vector<int> vert(n), horiz(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) horiz[i] += a[i][j];
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) vert[j] += a[i][j];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) ans += (vert[j] > horiz[i]);
  cout << ans << endl;
  return 0;
}
