#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = a[0], pos = 0;
  for (int i = 1; i < n; i++) {
    if ((i + 1) != n) {
      int x = max(a[i], a[i + 1]);
      if (x <= ans) ans = x;
      if (a[i + 1] == x) i++;
    } else {
      ans = min(ans, a[n - 1]);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
