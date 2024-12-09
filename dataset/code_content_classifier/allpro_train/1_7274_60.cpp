#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, s;
  cin >> n >> k >> s;
  if (((n - 1) * k < s) || (k > s)) {
    cout << "NO" << endl;
    return 0;
  } else {
    long long q = s / k, pres = 1, inc = s % k;
    cout << "YES\n";
    for (long long i = 0; i < k; ++i) {
      if (i % 2 == 0) {
        cout << pres + q + (inc > 0 ? 1 : 0) << ' ';
        pres = pres + q + (inc > 0 ? 1 : 0);
        inc--;
      } else {
        cout << pres - (q + (inc > 0 ? 1 : 0)) << ' ';
        pres = pres - (q + (inc > 0 ? 1 : 0));
        inc--;
      }
    }
  }
  return 0;
}
