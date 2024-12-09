#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
long long power(long long x, long long y, long long mod = 2e18) {
  long long ans = 1;
  x %= mod;
  while (y) {
    if (y & 1) ans = (x * ans) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool vis[101];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ct = 0;
  long long i = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == i + 1) {
      vis[i] = 1;
      ct++;
    } else
      break;
  }
  vis[i - 1] = 0;
  ct--;
  for (long long i = 0; i < n - 1; i++) {
    if (a[i] + 1 == a[i + 1]) {
      long long ct2 = 0;
      for (long long j = i + 1; j < n; j++) {
        if (a[j] + 1 == a[j + 1]) {
          ct2++;
        } else
          break;
      }
      ct = max(ct, ct2);
    }
  }
  for (long long i = 0; i < n; i++) {
    long long ct2 = 0;
    if (a[i] == 1000 - (n - i - 1)) {
      for (long long j = i + 1; j < n; j++) {
        ct2++;
        ct = max(ct, ct2);
      }
      break;
    }
  }
  if (ct < 0) ct = 0;
  cout << ct;
  return 0;
}
