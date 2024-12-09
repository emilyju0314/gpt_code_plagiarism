#include <bits/stdc++.h>
using namespace std;
const int O = 1e6 + 5;
int n, a[O], k;
struct triple {
  int u, v, w;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int o = 1; o <= t; ++o) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    vector<triple> ans;
    int d = sum / n;
    for (int i = 2; i <= n; ++i) {
      int y = (i - (a[i] % i)) % i;
      ans.push_back({1, i, y});
      a[i] += y;
      ans.push_back({i, 1, a[i] / i});
      a[i] = a[i] % i;
    }
    for (int i = 2; i <= n; ++i) {
      ans.push_back({1, i, d - a[i]});
    }
    cout << ans.size() << '\n';
    for (triple i : ans) cout << i.u << " " << i.v << " " << i.w << '\n';
    cout << '\n';
  }
}
