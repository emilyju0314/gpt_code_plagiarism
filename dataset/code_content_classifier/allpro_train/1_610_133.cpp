#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  long long int b[n + 1];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] *= (n - i + 1) * (i);
  }
  for (int i = 1; i <= n; i++) cin >> b[i];
  sort(a + 1, a + n + 1, greater<long long int>());
  sort(b + 1, b + n + 1);
  long long int ans = 0L;
  for (int i = 1; i <= n; i++) {
    ans += ((a[i] % 998244353) * b[i]) % 998244353;
    ans %= 998244353;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
