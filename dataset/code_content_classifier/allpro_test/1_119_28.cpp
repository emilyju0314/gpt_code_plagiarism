#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long u = 2;
    sort(a, a + n);
    while (1) {
      long long x = a[n - 1] + a[0];
      if (x != 0) {
        if (x % 2 == 0)
          a[0] = a[n - 1] = x / 2;
        else {
          a[0] = x / 2;
          a[n - 1] = (x / 2) + 1;
        }
      }
      sort(a, a + n);
      u = a[n - 1] - a[0];
      if (u == 0 || u == 1) break;
    }
    cout << u << "\n";
  }
  return 0;
}
