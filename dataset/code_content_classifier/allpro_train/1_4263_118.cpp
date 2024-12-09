#include <bits/stdc++.h>
using namespace std;
double startTime;
double getCurrentTime() {
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int power(long long int x, unsigned long long int y,
                    long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int sd;
    for (long long int i = 2; i <= n; i++) {
      if (n % i == 0) {
        sd = i;
        break;
      }
    }
    k--;
    long long int num = n + sd;
    for (long long int i = 2; i <= num; i++) {
      if (num % i == 0) {
        sd = i;
        break;
      }
    }
    cout << num + sd * k << endl;
  }
  return 0;
}
