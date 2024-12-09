#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, Mo = 1000000007;
long long a[N];
int fa[N], w[N], f[N];
inline int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch == '-' ? o = -1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return o * x;
}
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int main() {
  int n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = gi();
  for (int i = 2; i <= n; i++) fa[i] = gi();
  for (int i = n; i > 1; i--) a[fa[i]] += a[i];
  for (int i = 1; i <= n; i++) {
    long long t = a[1] / gcd(a[1], a[i]);
    if (t <= n) ++w[t];
  }
  for (int i = n; i; i--)
    for (int j = i + i; j <= n; j += i) w[j] += w[i];
  for (int i = n; i > 1; i--)
    if (w[i] >= i) {
      f[i] = 1;
      for (int j = i + i; j <= n; j += i) f[i] = (f[i] + f[j]) % Mo;
      ans = (ans + f[i]) % Mo;
    }
  cout << ans;
  return 0;
}
