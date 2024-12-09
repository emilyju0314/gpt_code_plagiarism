#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
long long int f[33] = {0};
long long int power[63] = {0};
void solve() {
  long long int n, k;
  cin >> n >> k;
  if (n >= 32) {
    cout << "YES " << n - 1 << '\n';
    return;
  }
  if (k == 1) {
    cout << "YES " << n - 1 << '\n';
    return;
  }
  long long int len = 3;
  long long int d = 1;
  k--;
  long long int curr = f[n - 1];
  while (true) {
    if (curr >= k) {
      cout << "YES " << n - d << '\n';
      return;
    }
    if (d == n) {
      cout << "NO\n";
      return;
    }
    if (k < (len)) {
      cout << "NO\n";
      return;
    }
    d++;
    k -= len;
    len = power[d + 1] - 1;
    if (f[n - d] >= inf / (len - 2)) {
      curr = inf;
    } else
      curr += (len - 2) * f[n - d];
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  f[0] = 0;
  for (long long int j = 1; j <= 32; j++) f[j] = 4 * f[j - 1] + 1;
  long long int t;
  cin >> t;
  power[0] = 1;
  for (long long int j = 1; j <= 62; j++) power[j] = power[j - 1] * 2;
  while (t--) {
    solve();
  }
  return 0;
}
