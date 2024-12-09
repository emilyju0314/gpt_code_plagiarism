#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int num;
  cin >> num;
  int n = 2 * num, a[n], i, x = 0, y = 0, j, k, it, cnt = 0, fa, b[n], c[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i += 2) {
    if (a[i] != a[i + 1]) {
      for (j = (i + 1); j < n; j++) {
        if (a[j] == a[i]) break;
      }
      x = j - i - 1;
      for (it = j; it > (i + 1); it--) {
        swap(a[it], a[it - 1]);
      }
      cnt += x;
    }
  }
  cout << cnt;
  return 0;
}
