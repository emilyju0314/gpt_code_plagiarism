#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long res_even = a[0];
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        res_even = gcd(res_even, a[i]);
      }
    }
    long long res_odd = a[1];
    for (long long i = 0; i < n; i++) {
      if (i % 2 != 0) {
        res_odd = gcd(res_odd, a[i]);
      }
    }
    if (res_odd == res_even || (res_odd == 1 && res_even == 1)) {
      cout << 0 << endl;
    } else {
      long long ans = 0;
      bool odd = true;
      bool even = true;
      if (res_odd == 1) {
        for (long long i = 0; i < n; i++) {
          if (i % 2 != 0) {
            if (a[i] % res_even == 0) {
              even = false;
            }
          }
        }
        if (even) {
          cout << res_even << endl;
        } else {
          cout << 0 << endl;
        }
      } else if (res_even == 1) {
        for (long long i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (a[i] % res_odd == 0) {
              odd = false;
            }
          }
        }
        if (odd) {
          cout << res_odd << endl;
        } else {
          cout << 0 << endl;
        }
      } else {
        for (long long i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (a[i] % res_odd == 0) {
              odd = false;
            }
          } else {
            if (a[i] % res_even == 0) {
              even = false;
            }
          }
        }
        if (odd) {
          cout << res_odd << endl;
        } else if (even) {
          cout << res_even << endl;
        } else {
          cout << 0 << endl;
        }
      }
    }
  }
}
