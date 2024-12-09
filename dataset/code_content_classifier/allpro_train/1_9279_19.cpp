#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
long long mpower(long long x, long long y, long long p);
long long modInv(long long a, long long m);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
bool isPrime(long long n);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, k, l, h, p, q, r, x, y, z, a, b, c, d, f, n, m,
      M = 1000000007;
  char ch, ch2, ch3;
  string s, s1, s2, s3;
  vector<long long> v, w;
  unordered_map<long long, long long> N;
  set<long long> S;
  set<long long>::iterator itr;
  cin >> n;
  f = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0) {
      cout << x / 2 << "\n";
    } else {
      if (x > 0) {
        if (f) {
          cout << x / 2 << "\n";
          f = 0;
        } else {
          cout << (x + 1) / 2 << "\n";
          f = 1;
        }
      } else {
        if (f) {
          cout << (x - 1) / 2 << "\n";
          f = 0;
        } else {
          cout << x / 2 << "\n";
          f = 1;
        }
      }
    }
  }
  return 0;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
  return res;
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
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
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
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (int i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
