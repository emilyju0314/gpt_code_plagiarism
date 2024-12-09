#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int N = 1e6 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 1e9 + 9;
const long long int lim = 1e12 + 5;
long long int a[N];
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p;
    cin >> n >> p;
    for (long long int i = 1; i <= n; i++) cin >> a[i];
    if (p == 1) {
      cout << n % 2 << '\n';
      continue;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    long long int pw = 0, id = 0;
    long long int ans = 0;
    for (long long int i = 1; i <= n; i++) {
      if (pw == 0) {
        pw = 1;
        id = a[i];
      } else {
        while (id > a[i] && pw <= lim) {
          id--;
          pw *= p;
        }
        if (pw > lim)
          ans = (ans - power(p, a[i]) + mod) % mod;
        else
          pw--;
      }
    }
    ans = (ans + power(p, id) * (pw % mod)) % mod;
    cout << ans << '\n';
  }
  return 0;
}
