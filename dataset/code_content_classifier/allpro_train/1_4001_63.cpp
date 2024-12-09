#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, i, j, k, m, p, x, y, f = 0, s = 0, ss = 0;
    cin >> n >> m;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (i = n - 1; i >= 0; i--) {
      f++;
      s = s + a[i];
      if (s / f >= m) {
        ss++;
      } else
        break;
    }
    cout << ss << endl;
  }
  return 0;
}
