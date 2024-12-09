#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans_br, ans_mom, ans_dad;
  if (d >= b || d > 2 * c) {
    cout << -1 << endl;
  } else {
    ans_br = max(d, c);
    if (ans_br > d * 2) {
      cout << -1 << endl;
    } else {
      ans_mom = max(max(b, 2 * d + 1), ans_br + 1);
      if (ans_mom > 2 * b) {
        cout << -1 << endl;
      } else {
        ans_dad = max(a, ans_mom + 1);
        if (ans_dad > 2 * a) {
          cout << -1 << endl;
        } else {
          cout << ans_dad << ' ' << ans_mom << ' ' << ans_br << endl;
        }
      }
    }
  }
  return 0;
}
