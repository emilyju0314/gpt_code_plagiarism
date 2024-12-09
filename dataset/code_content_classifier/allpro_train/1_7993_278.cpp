#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  const int MOD = 1e9 + 7;
  long long d = 1, others = 0;
  for (int i = 0; i < n; i++) {
    long long newd = 3 * others % MOD;
    long long newothers = (d + 2 * others % MOD) % MOD;
    d = newd;
    others = newothers;
  }
  cout << d;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
