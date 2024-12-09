#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
void solve() {
  long long int n, a;
  cin >> n;
  vector<long long int> v;
  v.push_back(0);
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  if (n <= 2 || n % 2 == 0) {
    cout << "-1" << endl;
    return;
  }
  long long int ans = 0;
  for (long long int i = n; i >= 3; i -= 2) {
    long long int val = max(v[i], v[i - 1]);
    ans += val;
    v[i] -= val;
    v[i - 1] -= val;
    v[(i - 1) / 2] -= val;
    v[i] = max(v[i], 0ll);
    v[i - 1] = max(v[i - 1], 0ll);
    v[(i - 1) / 2] = max(v[(i - 1) / 2], 0ll);
  }
  for (long long int i = 1; i <= n; i++) {
    ans += v[i];
  }
  cout << ans << endl;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
