#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n, ans = 1e5, k, i, t, j, m, x = 0, y = 0, z, c = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    c += (i - 1) >> 1;
    if (c >= m) {
      for (j = 1; j < i; j++) {
        cout << j << " ";
      }
      cout << i + ((c - m) << 1) << " ";
      for (j = i + 1; j <= n; j++) {
        cout << ans + 2 * n * j + 1 << " ";
      }
      return 0;
    }
  }
  return cout << -1, 0;
  ;
}
