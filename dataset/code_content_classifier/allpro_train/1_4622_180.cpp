#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const double EPS = 1e-15;
const long long INF = 1000000000 + 5;
const int MAXN2 = 40 + 5;
const long long p = 1e9 + 7;
long long f[MAXN];
long long f2[MAXN];
int a[MAXN];
int used[MAXN];
long long binpow(long long v, long long st) {
  long long ans = 1, a = v;
  for (; st; st >>= 1) {
    if (st & 1) {
      ans *= a;
      ans %= p;
    }
    a *= a;
    a %= p;
  }
  return ans;
}
int main() {
  int n, n2 = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      used[a[i]]++;
      used[i] = 2;
    } else
      n2++;
  }
  for (int i = 1; i <= n; i++) {
    if (used[i] == 1) k++;
  }
  f[0] = 1;
  f2[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * i) % p;
  }
  long long phi = p - 2;
  for (int i = 1; i <= n; i++) {
    f2[i] = binpow(f[i], phi);
  }
  long long ans = 0;
  int k2 = n2 - k;
  n = n2;
  for (int i = 0; i <= k2; i++) {
    long long cur = (f[k2] * f[n - i]) % p;
    cur = (cur * f2[i]) % p;
    cur = (cur * f2[k2 - i]) % p;
    if (i & 1) {
      ans -= cur;
      while (ans < 0) ans += p;
    } else {
      ans += cur;
      ans %= p;
    }
  }
  printf("%I64d", ans);
  return 0;
}
