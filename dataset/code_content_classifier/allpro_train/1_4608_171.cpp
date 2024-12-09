#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort((v).begin(), (v).end());
  long long ans = -INF;
  for (int i = n - 5; i <= n; i++) {
    long long cur = 1;
    for (int j = i; j < i + 5; j++) {
      cur *= v[j % n];
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
