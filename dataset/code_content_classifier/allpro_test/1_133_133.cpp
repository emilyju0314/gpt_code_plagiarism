#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
void solve() {
  int n;
  cin >> n;
  string ans;
  for (int i = 0; i < n - 2; i++) {
    string t;
    cin >> t;
    if (i == 0) {
      ans = t;
    } else if (t[0] == ans.back()) {
      ans += t[1];
    } else {
      ans += t;
    }
  }
  if (ans.length() != n) {
    ans += ans.back();
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
  return 0;
}
