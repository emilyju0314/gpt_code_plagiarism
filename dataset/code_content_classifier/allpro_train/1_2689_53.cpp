#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long mi, ma;
  mi = a - (b * 2);
  if (mi < 0) mi = 0;
  long long s, p, q;
  if (b == 0)
    ma = a;
  else if (b == 1)
    ma = a - 2;
  else {
    p = 1;
    for (long long i = 2; i <= a; i++) {
      p = p + i;
      if (p >= b) {
        q = i + 1;
        break;
      }
    }
    ma = a - q;
  }
  cout << mi << " " << ma;
  return 0;
}
