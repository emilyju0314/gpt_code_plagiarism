#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long inf = 1e9;
ll n, m, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int ans = 1000;
    for (int i = 1; i < n; i++) {
      ans = min(ans, v[i] - v[i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
