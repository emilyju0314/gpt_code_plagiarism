#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lowbit(long long x) { return x & -x; }
long long a[maxn];
long long b[maxn];
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n / 2; i++) {
    cin >> a[i];
    b[i * 2] = a[i];
  }
  long long x = 0;
  long long k = 0;
  for (long long i = 1; i <= n / 2; i++) {
    while (1) {
      long long p = x * x - k;
      if (p <= 0) {
        x++;
        continue;
      }
      long long c = x * x + a[i];
      long long d = sqrt(c + 0.5);
      if (d * d == c) {
        b[2 * i - 1] = p;
        break;
      } else
        x++;
      if (x >= 1e7) {
        cout << "No" << endl;
        return 0;
      }
    }
    k += b[2 * i] + b[2 * i - 1];
    if (x >= 1e7) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (long long i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
