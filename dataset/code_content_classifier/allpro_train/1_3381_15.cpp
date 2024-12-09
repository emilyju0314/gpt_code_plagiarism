#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, t, count, ans, x, mn;
  cin >> t;
  while (t--) {
    cin >> k;
    int a[7];
    for (i = 0, count = 0; i < 7; i++) {
      cin >> a[i];
      if (a[i] == 1) count++;
    }
    x = k / count;
    if (k % count == 0) x--;
    ans = x;
    for (i = 0, mn = 1e9; i < 7; i++) {
      j = i;
      x = 0;
      while (ans * count + x < k) {
        if (a[j % 7] == 1) x++;
        j++;
      }
      mn = fmin(mn, j - i);
    }
    cout << ans * 7 + mn << '\n';
  }
}
