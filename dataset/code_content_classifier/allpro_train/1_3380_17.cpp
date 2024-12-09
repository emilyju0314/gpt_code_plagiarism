#include <bits/stdc++.h>
using namespace std;
int MOD(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int gcd(long long int a, long long int b) {
  if (b == 1)
    return 1;
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long int mod(long long int x) {
  if (x >= 0)
    return x;
  else
    return -x;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = n - 1;
  int sum = 0;
  for (; m > 0 && i >= 0; i--) {
    if (sum + a[i] > k) {
      m--;
      sum = 0;
    }
    if (m == 0) break;
    sum += a[i];
  }
  cout << n - i - 1;
  return 0;
}
