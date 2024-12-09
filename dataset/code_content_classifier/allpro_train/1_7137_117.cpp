#include <bits/stdc++.h>
using namespace std;
int a[4], i, b[10001], c[10001], r, mx, x;
bool kt;
int main() {
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  r = 0;
  while (a[0] != 1 || a[1] != 1 || a[2] != 1 || a[3] != 1) {
    kt = false;
    mx = 0;
    x = 0;
    for (i = 0; i <= 3; i++)
      if (a[i] % 2 == 0 && a[(i + 1) % 4] % 2 == 0) {
        if (a[i] + a[(i + 1) % 4] > mx) {
          mx = a[i] + a[(i + 1) % 4];
          x = i;
        }
        kt = true;
      }
    if (kt) {
      r++;
      b[r] = 0;
      c[r] = x + 1;
      a[x] /= 2;
      a[(x + 1) % 4] /= 2;
      continue;
    }
    for (i = 0; i <= 3; i++)
      if (a[i] % 2 == 1 && a[(i + 1) % 4] % 2 == 1) {
        if (a[i] + a[(i + 1) % 4] > mx) {
          mx = a[i] + a[(i + 1) % 4];
          x = i;
        }
        kt = true;
      }
    if (!kt || mx == 2)
      for (i = 0; i <= 3; i++)
        if (a[i] + a[(i + 1) % 4] > mx) {
          mx = a[i] + a[(i + 1) % 4];
          x = i;
        }
    r++;
    b[r] = 1;
    c[r] = x + 1;
    a[x]++;
    a[(x + 1) % 4]++;
  }
  for (i = 1; i <= r; i++) {
    if (b[i])
      cout << "+";
    else
      cout << "/";
    cout << c[i] << endl;
  }
  return 0;
}
