#include <bits/stdc++.h>
using namespace std;
int _2[4], _3[4], c[4];
long long a[4];
int main() {
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 4; ++i) {
    while ((2 * a[i]) % 3 == 0) ++_3[i], a[i] = (2 * a[i]) / 3;
  }
  for (int i = 0; i < 4; ++i) {
    while (a[i] % 2 == 0) ++_2[i], a[i] /= 2;
  }
  if (a[0] * a[1] != a[2] * a[3]) {
    cout << -1 << endl;
  } else {
    c[0] = c[2] = min(_2[0] + _2[1], _2[2] + _2[3]);
    c[1] = c[3] = min(_3[0] + _3[1], _3[2] + _3[3]);
    for (int i = 0; i < 2; ++i) {
      while (c[0] && _2[i]) {
        --c[0];
        --_2[i];
        a[i] *= 2;
      }
    }
    for (int i = 0; i < 2; ++i) {
      while (c[1] && _3[i]) {
        --c[1];
        --_3[i];
        a[i] = (a[i] / 2) * 3;
      }
    }
    for (int i = 2; i < 4; ++i) {
      while (c[2] && _2[i]) {
        --c[2];
        --_2[i];
        a[i] *= 2;
      }
    }
    for (int i = 2; i < 4; ++i) {
      while (c[3] && _3[i]) {
        --c[3];
        --_3[i];
        a[i] = (a[i] / 2) * 3;
      }
    }
    cout << abs(_2[0] + _2[1] - _2[2] - _2[3]) +
                abs(_3[0] + _3[1] - _3[2] - _3[3])
         << endl;
    cout << a[0] << " " << a[1] << endl;
    cout << a[2] << " " << a[3] << endl;
  }
  return 0;
}
