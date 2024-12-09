#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5;
long long po(int, int);
void solve() {
  long long a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  long long x = min({b, c, d});
  long long y = min(a, d);
  long long z;
  long long ans = 0;
  if (f >= e) {
    z = d - x;
    ans = max({x * f, y * e, x * f + min(a, z) * e});
  } else {
    z = d - y;
    ans = max({x * f, y * e, y * e + min({b, c, z}) * f});
  }
  cout << ans << "\n";
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
long long po(int a, int b) {
  if (b == 0) return 1;
  long long ans = 1;
  if (b % 2 == 0) {
    ans = po(a, b / 2) % M;
    ans = (ans % M * ans % M) % M;
  } else {
    ans = po(a, (b - 1) / 2) % M;
    ans = (ans % M * ans % M * a) % M;
  }
  return ans % M;
}
