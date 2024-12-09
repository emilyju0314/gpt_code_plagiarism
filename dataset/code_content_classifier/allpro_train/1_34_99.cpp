#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int h = 0, o = 0, t = 0, f = t * 2 + o + h / 2;
  while (f < n) {
    if (t + 1 <= c && n - f >= 2) {
      t++;
    } else if (o + 1 <= b && n - f >= 1) {
      o++;
    } else if (h + 2 <= a && n - f >= 1) {
      h += 2;
    } else {
      cout << 0 << '\n';
      return 0;
    }
    f = t * 2 + o + h / 2;
    if (t == c && o == b && h == a && f < n) {
      cout << 0 << "\n";
      return 0;
    }
  }
  int sum = 0, th = h, to = o;
  for (int i = t; i >= 0; i--) {
    sum++;
    while (a - th >= 2 && to > 0) {
      to--;
      th += 2;
      sum++;
    }
    if (i > 0 && (b + (a / 2) + (i - 1) * 2 >= n)) {
      int temh = 0, temo = 0, te = (i - 1) * 2 + temo + temh / 2;
      while (te < n) {
        if (temo + 1 <= b && n - te >= 1) {
          temo++;
        } else if (temh + 2 <= a && n - te >= 1) {
          temh += 2;
        } else {
          cout << sum << '\n';
          return 0;
        }
        te = (i - 1) * 2 + temo + temh / 2;
      }
      th = temh;
      to = temo;
    } else {
      break;
    }
  }
  cout << sum << '\n';
  return 0;
}
