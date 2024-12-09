#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void ghost() {
  long long int n, i = 0, j, y, k, w, a = 0, b = 0, l, x = 0, t = 0, d = 0,
                   m = 0, p = 0;
  cin >> n >> p >> w >> d;
  m = gcd(w, d);
  if (p % m != 0)
    cout << "-1";
  else if (n * w < p)
    cout << "-1";
  else {
    while (1) {
      p = p - i * d;
      i = 1;
      if (p % w == 0) {
        cout << p / w << " " << a << " " << n - p / w - a;
        break;
      }
      a++;
      if (p < 0 || a > n) {
        cout << "-1";
        break;
      }
    }
  }
}
signed main() {
  long long int test = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (test--) ghost();
  return 0;
}
