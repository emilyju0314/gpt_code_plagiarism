#include <bits/stdc++.h>
using namespace std;
long long l, r, k, ans = 0x3f3f3f3f3f3f3f3fll;
int Count(int x) {
  int re = 0;
  for (; x; x -= x & -x) ++re;
  return re;
}
int main() {
  long long i, j;
  cin >> l >> r >> k;
  if (r - l + 1 <= 4) {
    int _ans;
    for (i = 1; i < 1 << r - l + 1; i++)
      if (Count(i) <= k) {
        long long temp = 0;
        for (j = 0; j < r - l + 1; j++)
          if (i & (1 << j)) temp ^= l + j;
        if (temp <= ans) ans = temp, _ans = i;
      }
    cout << ans << endl;
    cout << Count(_ans) << endl;
    for (j = 0; j < r - l + 1; j++)
      if (_ans & (1 << j)) cout << l + j << ' ';
    return 0;
  }
  if (k >= 4) {
    if (l & 1) ++l;
    cout << 0 << endl;
    cout << 4 << endl;
    for (i = 0; i < 4; i++) cout << l + i << ' ';
    return 0;
  }
  if (k >= 3) {
    for (i = 1; i < l; i = i << 1 | 1)
      ;
    if (((i + 1) | (i + 1 >> 1)) <= r) {
      cout << 0 << endl;
      cout << 3 << endl;
      cout << i << ' ' << ((i + 1) | (i >> 1)) << ' '
           << ((i + 1) | (i + 1 >> 1)) << ' ';
      return 0;
    }
  }
  if (k >= 2) {
    if (l & 1) ++l;
    cout << 1 << endl;
    cout << 2 << endl;
    cout << l << ' ' << l + 1 << ' ';
    return 0;
  }
  cout << l << endl;
  cout << 1 << endl;
  cout << l << ' ';
  return 0;
}
