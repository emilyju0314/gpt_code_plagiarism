#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long a[n + 1], b[m + 1];
  long long xo = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], xo ^= a[i];
  for (long long i = 0; i < m; i++) cin >> b[i], xo ^= b[i];
  if (xo != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i == n - 1 && j == m - 1)
        cout << (a[n - 1] ^ xo);
      else if (i == n - 1)
        xo ^= b[j], cout << b[j] << " ";
      else if (j == m - 1)
        cout << a[i] << " ";
      else
        cout << "0 ";
    }
    cout << "\n";
  }
  return 0;
}
