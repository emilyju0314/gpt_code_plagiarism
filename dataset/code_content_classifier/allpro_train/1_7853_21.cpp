#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const long long inf = 0x3f3f3f3f;
const int mod = 998244353;
const int MAX = 123123;
const int N = 1e5 + 5;
const double eps = 1e-6;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long read1() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int poww(int a, int b) {
  int ans = 1, base = a;
  while (b != 0) {
    if ((b & 1) != 0) ans *= base;
    base *= base;
    b >>= 1;
  }
  return ans;
}
int lowbit(long long x) { return x & (-x); }
int n, k;
long long a[55];
bool dp[55][55];
int main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int T = 60; T >= 0; --T) {
    memset(dp, 0, sizeof(dp));
    ans += 1ll << T;
    dp[0][0] = 1;
    for (long long i = 0; i < n; i++) {
      long long ret = a[i];
      for (int j = i; j < n; ret += a[++j])
        if ((ret & ans) == ans)
          for (int l = 0; l < k; ++l) dp[j + 1][l + 1] |= dp[i][l];
    }
    if (!dp[n][k]) {
      ans -= 1ll << T;
    }
  }
  cout << ans << endl;
  return 0;
}
