#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t = 1;
  while (t--) {
    long long n, ans = 9999999999999;
    cin >> n;
    long long s = n;
    long long cnt = 0;
    while (s) {
      cnt++;
      s = s / 10;
    }
    if (cnt % 2 == 1) {
      cnt++;
      for (long long i = 1; i <= cnt / 2; i++) cout << 4;
      for (long long i = (cnt / 2) + 1; i <= cnt; i++) cout << 7;
      cout << "\n";
    } else {
      long long x = pow(2, cnt + 2);
      for (long long i = 0; i <= x; i++) {
        vector<long long> v;
        long long z = i;
        while (z) {
          if (z % 2 == 0)
            v.push_back(0);
          else
            v.push_back(1);
          z = z / 2;
        }
        while (v.size() < cnt) {
          v.push_back(0);
        }
        long long cmp = 0;
        for (long long j = v.size() - 1; j >= 0; j--) {
          if (v[j] == 0) {
            cmp = cmp * 10 + 4;
          } else
            cmp = cmp * 10 + 7;
        }
        if (cmp >= n) {
          long long zx = cmp, cn = 0, to = 0;
          while (zx) {
            to++;
            if (zx % 10 == 7) cn++;
            zx = zx / 10;
          }
          if (cn * 2 == to) {
            ans = min(cmp, ans);
          }
        }
        cmp = 0;
        for (long long j = v.size() - 1; j >= 0; j--) {
          if (v[j] == 0) {
            cmp = cmp * 10 + 7;
          } else
            cmp = cmp * 10 + 4;
        }
        if (cmp >= n) {
          long long zx = cmp, cn = 0, to = 0;
          while (zx) {
            to++;
            if (zx % 10 == 7) cn++;
            zx = zx / 10;
          }
          if (cn * 2 == to) {
            ans = min(cmp, ans);
          }
        }
      }
      cout << ans << "\n";
    }
  }
}
