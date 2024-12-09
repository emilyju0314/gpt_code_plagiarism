#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, h, ans = 0;
    cin >> n >> a >> b >> h;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        ans += min(a, b + h);
      else
        ans += min(a + h, b);
    }
    cout << ans << endl;
  }
}
