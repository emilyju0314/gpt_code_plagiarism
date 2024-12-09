#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double epsilon = 1e-9;
const int oo = 1e9 + 10;
long long int binpow(long long int x, long long int ex,
                     long long int mod = 1000000007) {
  x %= mod;
  long long int res = 1;
  while (ex > 0) {
    if (ex & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    ex >>= 1;
  }
  return res;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int ans = (binpow(3, n, m) - 1 + m) % m;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
