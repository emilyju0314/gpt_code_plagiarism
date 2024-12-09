#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long x = log2(r);
  long long ans = 0;
  for (int i = 0; i < x; i++) {
    ans += (1LL << i);
  }
  if (r - ans >= (1LL << x)) ans += (1LL << x);
  if (l > ans) {
    ans = l;
    vector<int> binary(64);
    for (int i = 63; i >= 0; i--) {
      if ((ans >> i) & 1)
        binary[i] = 1;
      else
        binary[i] = 0;
    }
    for (int i = 0; i < 64; i++) {
      if (binary[i] == 0) {
        if ((1LL << i) + ans <= r) {
          ans += (1LL << i);
        } else
          break;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
