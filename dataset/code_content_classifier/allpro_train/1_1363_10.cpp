#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  while (cin >> k >> d >> t) {
    long double sum = 0;
    if (k == d) {
      sum = t;
      cout << fixed << setprecision(1) << sum << endl;
    }
    if (k > d) {
      if (k % d == 0) {
        sum = t;
        cout << fixed << setprecision(1) << sum << endl;
      } else {
        long long zhouqi = k / d;
        zhouqi++;
        long long yuwen = zhouqi * d - k;
        t = 2 * t;
        long long zonwen = k * 2 + yuwen;
        sum = (t / zonwen) * (zhouqi * d);
        yuwen = t % zonwen;
        if (yuwen <= 2 * k)
          sum = sum + (double)((double)yuwen / (double)2);
        else {
          yuwen = yuwen - 2 * k;
          sum = sum + k + yuwen;
        }
        cout << fixed << setprecision(1) << sum << endl;
      }
    }
    if (k < d) {
      t = 2 * t;
      long long zonwen = k * 2 + d - k;
      long long cishu = t / zonwen;
      long long yuwen = t % zonwen;
      sum = cishu * d;
      if (yuwen <= 2 * k)
        sum = sum + (double)((double)yuwen / (double)2);
      else {
        yuwen = yuwen - 2 * k;
        sum = sum + k + yuwen;
      }
      cout << fixed << setprecision(1) << sum << endl;
    }
  }
}
