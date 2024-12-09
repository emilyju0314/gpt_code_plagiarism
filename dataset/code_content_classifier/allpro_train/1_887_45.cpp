#include <bits/stdc++.h>
using namespace std;
void shikhar7s(long long int cas) {
  long long int n, k, i;
  cin >> n >> k;
  long long int a[n], l = -1, c = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (l != a[i]) {
      c++;
      l = a[i];
    }
  }
  if (k == 1) {
    if (k >= c)
      cout << 1 << "\n";
    else
      cout << -1 << "\n";
  } else if (k >= c) {
    cout << 1 << "\n";
  } else {
    long long int x = (c - k);
    long long int ans = x / (k - 1);
    if (x % (k - 1)) ans++;
    ans++;
    cout << ans << "\n";
  }
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  long long int cas = 1;
  while (cas <= t) {
    shikhar7s(cas);
    cas++;
  }
  return 0;
}
