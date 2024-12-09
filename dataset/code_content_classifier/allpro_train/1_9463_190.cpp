#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-6;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long double l;
    long long n;
    cin >> n >> l;
    long double a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long double low = 0;
    long double high = l;
    long double res = 0;
    long long itr = 0;
    while (itr < 1000) {
      long double mid = (low + high) / 2.0;
      long double t1 = 0.0;
      long double t2 = 0.0;
      long double cur_a = 0;
      long double cur_s = 1.0;
      bool f = 0;
      for (long long i = 0; i < n; i++) {
        if (a[i] >= mid) {
          long double dist = mid - cur_a;
          t1 += (dist / cur_s);
          f = 1;
          break;
        } else {
          long double dist = a[i] - cur_a;
          t1 += (dist / cur_s);
        }
        cur_a = a[i];
        cur_s++;
      }
      if (!f) {
        long double dist = mid - cur_a;
        t1 += (dist / cur_s);
      }
      cur_s = 1.0;
      long double cur_b = l;
      f = 0;
      for (long long i = n - 1; i >= 0; i--) {
        if (a[i] <= mid) {
          long double dist = cur_b - mid;
          t2 += (dist / cur_s);
          f = 1;
          break;
        } else {
          long double dist = cur_b - a[i];
          t2 += (dist / cur_s);
        }
        cur_b = a[i];
        cur_s++;
      }
      if (!f) {
        long double dist = cur_b - mid;
        t2 += (dist / cur_s);
      }
      res = t1;
      if (t1 < t2) {
        low = mid;
      } else
        high = mid;
      itr++;
    }
    cout << setprecision(10) << fixed << res << "\n";
  }
}
