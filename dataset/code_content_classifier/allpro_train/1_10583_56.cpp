#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ans = 0, m, n;
    cin >> n >> m;
    if (n >= 3) {
      ans = 2 * m;
    } else if (n == 2) {
      ans = m;
    } else
      ans = 0;
    cout << ans << endl;
  }
  return 0;
}
