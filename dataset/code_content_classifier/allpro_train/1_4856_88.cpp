#include <bits/stdc++.h>
using namespace std;
long long modInverse(long long a, long long m);
long long gcd(long long a, long long b);
long long power(long long x, unsigned long long y, unsigned long long m);
long long logint(long long x, long long y);
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long power(long long x, unsigned long long y, unsigned long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long logint(long long x, long long y) {
  long long ans = 0;
  long long a = 1;
  for (long long i = 0; i < x; i++) {
    if (x <= a) {
      return ans;
    }
    ans++;
    a *= y;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string st;
  cin >> st;
  long long cc = 0;
  long long dd = 0;
  long long ar[n];
  for (long long j = 0; j < n; j++) {
    if (st[j] == '(') {
      ar[j] = cc;
      if (cc == 0) {
        cc = 1;
      } else {
        cc = 0;
      }
    } else if (st[j] == ')') {
      ar[j] = dd;
      if (dd == 0) {
        dd = 1;
      } else {
        dd = 0;
      }
    }
  }
  for (long long j = 0; j < n; j++) {
    cout << ar[j];
  }
}
