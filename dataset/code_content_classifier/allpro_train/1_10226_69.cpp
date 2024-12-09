#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  long long l, r;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    if (l == r) {
      if (l % 2 == 0) {
        cout << l << endl;
        continue;
      } else {
        cout << -l << endl;
        continue;
      }
    }
    if (l % 2 == 0) {
      if ((r - l + 1) % 2 == 0) {
        cout << 0 - (r - l + 1) / 2 << endl;
        continue;
      } else {
        cout << (l - r) / 2 + r << endl;
        continue;
      }
    } else {
      if ((r - l + 1) % 2 == 0) {
        cout << (r - l + 1) / 2 << endl;
        continue;
      } else {
        cout << (r - l) / 2 - r << endl;
        continue;
      }
    }
  }
  return 0;
}
