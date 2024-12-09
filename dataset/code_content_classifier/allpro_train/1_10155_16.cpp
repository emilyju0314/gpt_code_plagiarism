#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (T % 2 == 0 && a[i] == T / 2)
      ans[i] = (cnt++) % 2;
    else if (2 * a[i] < T)
      ans[i] = 1;
    else
      ans[i] = 0;
  }
  for (int x : ans) cout << x << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
