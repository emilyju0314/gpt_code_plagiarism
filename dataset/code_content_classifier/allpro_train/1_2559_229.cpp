#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, x, resp = 1;
  cin >> s >> x;
  if ((s - x) % 2 != 0) {
    cout << 0;
    return 0;
  }
  long long a = (s - x) / 2;
  s = (long long)1 << 40;
  for (int i = 0; i < 40; i++) {
    s = s >> 1;
    if ((x & s) > 0) {
      if ((a & s) > 0) {
        cout << 0;
        return 0;
      } else {
        resp = resp * 2;
      }
    }
  }
  if (a == 0) {
    cout << resp - 2;
  } else {
    cout << resp;
  }
  return 0;
}
