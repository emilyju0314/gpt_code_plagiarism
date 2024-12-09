#include <bits/stdc++.h>
const long long INF = 1e18;
using namespace std;
void SOE(long long n) {
  bool isPrime[n + 1];
  memset(isPrime, true, sizeof(isPrime));
  for (long long p = 2; p <= n; p++) {
    if (isPrime[p]) {
      for (long long i = p * p; i <= n; i += p) isPrime[i] = false;
    }
  }
}
long long POWER(long long base, long long expo) {
  long long num = 1;
  long long i = expo;
  while (i) {
    num = num * base;
    i--;
  }
  return num;
}
int main() {
  long long t = 1;
  while (t--) {
    long long n, sum = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    long long m;
    cin >> m;
    for (long long i = 1; i <= m; i++) {
      long long q;
      cin >> q;
      cout << sum - a[n - q] << endl;
    }
  }
  return 0;
}
