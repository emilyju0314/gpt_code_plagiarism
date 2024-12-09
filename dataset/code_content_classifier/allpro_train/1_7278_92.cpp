#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long INF = 1ll << 60;
long long exp(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  long long a[n];
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (m[a[i]] == 0) m[a[i]] = -INF;
    m[a[i]] = max(m[a[i]], i);
  }
  long long ans[n];
  for (long long i = 0; i < n; i++) ans[i] = 2;
  ans[0] = 1;
  long long reach = -INF;
  for (long long i = 0; i < n; i++) {
    if (m[a[i]] != i) reach = max(m[a[i]], reach);
    if (i <= reach && i != reach) ans[i] = 1;
  }
  long long z = 1, ansi = 1;
  for (long long i = 0; i < n; i++) {
    if (ans[i] == 2) {
      ansi = (2 * ansi) % MOD;
    }
  }
  if (m[a[0]] != 0) ansi /= 2;
  cout << ansi << endl;
}
