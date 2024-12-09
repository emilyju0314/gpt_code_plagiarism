#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      string s =
          string() + a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1] + a[i][j];
      sort(begin(s), end(s));
      if (s == "acef") {
        ++ans;
      }
    }
  }
  cout << ans << "\n";
}
