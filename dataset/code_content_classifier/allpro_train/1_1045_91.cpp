#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, i, n, f;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    f = 0;
    for (i = 0; i <= n / 2 - 1; i++) {
      if (abs(s[i] - s[n - 1 - i]) == 2 || abs(s[i] - s[n - 1 - i]) == 0)
        f = 1;
      else {
        f = 0;
        break;
      }
    }
    if (f == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
