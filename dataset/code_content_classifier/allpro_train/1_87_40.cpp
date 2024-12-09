#include <bits/stdc++.h>
using namespace std;
int main() {
  int last, ans1 = 0, ans2 = 0, dig, key, k1, k2;
  cout << "? 0 0" << endl;
  cin >> key;
  last = key;
  for (int i = 29; i >= 0; i--) {
    dig = 1 << i;
    if (last == 0) {
      cout << "? " << dig + ans1 << " " << ans2 << endl;
      cin >> k1;
      cout << "? " << ans1 << " " << dig + ans2 << endl;
      cin >> k2;
      if (k1 == -1 && k2 == 1) ans1 += dig, ans2 += dig;
    } else if (last == 1) {
      cout << "? " << dig + ans1 << " " << dig + ans2 << endl;
      cin >> k1;
      if (k1 == -1) {
        ans1 += dig;
        cout << "? " << ans1 << " " << ans2 << endl;
        cin >> k2;
        last = k2;
      } else {
        cout << "? " << ans1 << " " << dig + ans2 << endl;
        cin >> k2;
        if (k2 == 1) ans1 += dig, ans2 += dig;
      }
    } else if (last == -1) {
      cout << "? " << dig + ans1 << " " << dig + ans2 << endl;
      cin >> k1;
      if (k1 == 1) {
        ans2 += dig;
        cout << "? " << ans1 << " " << ans2 << endl;
        cin >> k2;
        last = k2;
      } else {
        cout << "? " << dig + ans1 << " " << ans2 << endl;
        cin >> k2;
        if (k2 == -1) ans1 += dig, ans2 += dig;
      }
    }
  }
  cout << "! " << ans1 << " " << ans2 << endl;
  return 0;
}
