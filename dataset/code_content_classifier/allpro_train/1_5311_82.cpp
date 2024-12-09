#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxu = 200005;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k = 0, n, t = 1, m, l = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << max(0ll, n - 2) << "\n";
  }
  return 0;
}
