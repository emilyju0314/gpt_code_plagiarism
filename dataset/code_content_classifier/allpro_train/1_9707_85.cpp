#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
const int LIM = 2e5 + 5, MOD = 1e9 + 7;
long long n, m, t, x, y, k, l;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> l;
  if (n - k < l) {
    cout << -1 << "\n";
    return 0;
  } else {
    y = (l + k) / m;
    if ((l + k) % m != 0) y++;
    if (y * m <= n) {
      cout << y << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
