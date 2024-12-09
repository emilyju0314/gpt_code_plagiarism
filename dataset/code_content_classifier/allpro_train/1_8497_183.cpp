#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int min = INT_MAX, max = INT_MIN, k, n, ans;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < min) {
        min = a[i];
      }
      if (a[i] > max) {
        max = a[i];
      }
    }
    if (min + k >= max - k) {
      ans = min + k;
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
