#include <bits/stdc++.h>
const long long INF = 1e18;
const long long N = 1e6 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
vector<long long> prime, g[N];
long long n, a[N], m, k;
long long POWER(long long base, long long expo) {
  long long ret = 1;
  while (expo) {
    if (expo & 1) ret = ret * base;
    expo >>= 1;
    base = base * base;
  }
  return ret;
}
void SOE(long long n) {
  bool isPrime[n + 1];
  memset(isPrime, true, sizeof(isPrime));
  for (long long p = 2; p <= n; p++) {
    if (isPrime[p]) {
      for (long long i = p * p; i <= n; i += p) isPrime[i] = false;
    }
  }
}
int main() {
  long long test_case = 1;
  while (test_case--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long ans = INF, tt;
    for (long long t = 1; t <= 100; t++) {
      long long cost = 0;
      for (long long i = 1; i <= n; i++) {
        if (abs(t - a[i]) > 1) {
          if (a[i] < t)
            cost += (t - 1 - a[i]);
          else
            cost += (a[i] - (t + 1));
        }
      }
      if (cost < ans) {
        tt = t;
        ans = cost;
      }
    }
    cout << tt << " " << ans;
  }
  return 0;
}
