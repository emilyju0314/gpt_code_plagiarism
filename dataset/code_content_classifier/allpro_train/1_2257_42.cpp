#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
  return res;
}
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long ncr(long long n, long long r) {
  if (r == 0)
    return 1;
  else if (r == 1)
    return n;
  else
    return ((((n * ncr(n - 1, r - 1)) % 1000000007) * modInv(r, 1000000007))) %
           1000000007;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long pos = 0;
  long long neg = 0;
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  long long mn = LONG_LONG_MAX;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] > 0)
      pos++;
    else if (a[i] < 0)
      neg++;
    mn = min(mn, abs(a[i]));
    sum += abs(a[i]);
  }
  if (pos == n || neg == n) {
    sum -= 2 * mn;
  }
  cout << sum << endl;
}
