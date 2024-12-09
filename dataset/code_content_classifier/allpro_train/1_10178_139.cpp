#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const long long INF = 1e9;
int main() {
  long long n, ans = 1;
  cin >> n;
  for (long long i = 1; i <= (long long)sqrt((double)(n)); i++) {
    if (n % i == 0) {
      bool t = 1;
      for (long long j = 2; j * j <= i; j++) {
        if (i % (j * j) == 0) {
          t = 0;
          break;
        }
      }
      if (t) {
        ans = max(ans, i);
      }
      t = 1;
      for (long long j = 2; j * j <= (n / i); j++) {
        if ((n / i) % (j * j) == 0) {
          t = 0;
          break;
        }
      }
      if (t) {
        ans = max(ans, n / i);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
