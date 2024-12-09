#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int a[200005], b[200005], q[200005];
int main() {
  int j, k, i, T, ca = 0, K = 0, m, n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]), b[i]++;
  a[n] = 1000000007;
  b[n] = a[n] + 1;
  long long ans = 0;
  int sum = 0, p;
  for (int i = 0; i < n; i++) {
    int l = max(a[i], a[i + 1]), r = min(b[i], b[i + 1]);
    if (l < r) {
      p = 1LL * (b[i] - a[i]) * (b[i + 1] - a[i + 1]) % 1000000007;
      p = pow(p, 1000000007 - 2);
      K = 1LL * (r - l) * p % 1000000007;
    } else
      K = 0;
    K = (1 - K + 1000000007) % 1000000007;
    q[i] = K;
    ans += K;
    ans += 2LL * K * sum % 1000000007;
    if (i) add(sum, q[i - 1]);
  }
  ans %= 1000000007;
  for (int i = 0; i < n - 1; i++) {
    K = (1 - (1 - q[i]) - (1 - q[i + 1])) % 1000000007;
    int l = max(a[i], a[i + 1]), r = min(b[i], b[i + 1]);
    Max(l, a[i + 2]), Min(r, b[i + 2]);
    if (l < r) {
      p = 1LL * (b[i] - a[i]) * (b[i + 1] - a[i + 1]) % 1000000007 *
          (b[i + 2] - a[i + 2]) % 1000000007;
      p = pow(p, 1000000007 - 2);
      p = 1LL * (r - l) * p % 1000000007;
      K = (K + p) % 1000000007;
    }
    ans += 2LL * K;
  }
  ans %= 1000000007;
  if (ans < 0) ans += 1000000007;
  printf("%lld\n", ans);
}
