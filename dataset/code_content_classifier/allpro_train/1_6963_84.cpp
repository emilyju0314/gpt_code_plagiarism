#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  unsigned long long l, r, val = 1;
  while (n--) {
    cin >> l >> r;
    for (long long k = 0; k < 64; k++) {
      if ((l | val << k) <= r) {
        l |= (val << k);
      } else
        break;
    }
    cout << l << endl;
  }
  return 0;
}
