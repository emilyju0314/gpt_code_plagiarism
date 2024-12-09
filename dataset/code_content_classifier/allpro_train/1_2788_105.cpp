#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, rating;
  cin >> n >> rating;
  std::vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  long long int zero = 0;
  for (long long int i = 0; i < n; i++) {
    if (v[i] == rating) {
      zero++;
    }
  }
  if (zero == n) {
    cout << "0" << '\n';
    return;
  }
  if (zero > 0) {
    cout << "1" << '\n';
    return;
  }
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    sum += v[i];
  }
  if (sum % n == 0 && sum / n == rating) {
    cout << "1" << '\n';
    return;
  }
  cout << "2" << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
