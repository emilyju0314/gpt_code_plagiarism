#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string ans;
  for (int i = 0; i < n; i++) {
    ans += s[i % k];
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] < ans[i])
      break;
    else if (s[i] > ans[i]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << n << "\n" << ans;
    return 0;
  }
  int x = k - 1;
  while (ans[x] == '9') {
    for (int i = 0; i < n; i++) {
      if (i % k == x) ans[i] = '0';
    }
    x--;
  }
  for (int i = 0; i < n; i++) {
    if (i % k == x) ans[i]++;
  }
  cout << n << "\n" << ans;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
