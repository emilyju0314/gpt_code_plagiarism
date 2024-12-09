#include <bits/stdc++.h>
using namespace std;
const long long int dx[4] = {-1, 0, 1, 0};
const long long int dy[4] = {0, -1, 0, 1};
const long long int mod = 1000 * 1000 * 1000 + 7;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int power_mod(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int sumofdigits(long long int n) {
  long long int out = 0;
  while (n) {
    out += (n % 10);
    n /= 10;
  }
  return out;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b & 1) return a * power(a, b - 1);
  long long int res = power(a, b / 2);
  return res * res;
}
long long int log(long long int d) { return log2(d); }
bool isPower(long long int x, long long int y) {
  if (x == 1) return (y == 1);
  long long int pow = 1;
  while (pow < y) pow *= x;
  return (pow == y);
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
bool compare(const pair<long long int, long long int> &a,
             const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
long long int i, j;
long long int phi(long long int n) {
  long long int result = n;
  for (long long int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      result -= result / p;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
int main() {
  long long int tt;
  cin >> tt;
  for (int _tt = 0; _tt < tt; _tt++) {
    long long int a, m;
    cin >> a >> m;
    long long int x = gcd(a, m);
    cout << phi(m / x) << "\n";
  }
}
