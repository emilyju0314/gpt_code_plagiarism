#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, L, v, l, r, f = 0, d1, d2, dd, h, s1, ans, dd2;
  cin >> t;
  long long b[t + 3];
  for (int i = 0; i < t; i++) {
    b[i] = 0;
    ans = 0;
    cin >> L >> v >> l >> r;
    d1 = l - 1;
    d2 = L - r;
    h = r - l + 1;
    f = L / v;
    ans += d1 / v;
    dd2 = (L - d2 + 1) / v;
    if (dd2 * v > r)
      ans += (f - dd2 + 1);
    else
      ans += (f - dd2);
    b[i] = ans;
  }
  for (int i = 0; i < t; i++) {
    cout << b[i] << endl;
  }
}
