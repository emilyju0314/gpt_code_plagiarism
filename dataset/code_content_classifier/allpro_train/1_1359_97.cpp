#include <bits/stdc++.h>
using namespace std;
int n, a[101], s[101];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  int ans = max(n - s[n], s[n]);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) {
      ans = max(ans, s[n] - s[i - 1] + i - s[i]);
    }
  }
  cout << ans;
}
