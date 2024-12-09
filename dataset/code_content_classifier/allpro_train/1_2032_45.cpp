#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n;
int Read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
void Put1(int x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
void Put(int x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
bool vis[MAXN];
int prime[MAXN], pn, ys[MAXN], tot;
void sieve(int x) {
  for (int i = 2; i <= x; ++i) {
    if (!vis[i]) prime[++pn] = i;
    for (int j = 1; j <= pn && i * prime[j] <= x; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int getphi(int x) {
  int ret = x;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      ret = ret / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  if (x > 1) ret = ret / x * (x - 1);
  return ret;
}
int qpow(int x, int y, int MOD) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % MOD;
    x = 1ll * x * x % MOD;
    y >>= 1;
  }
  return ret;
}
void solve3() {
  if (n == 1) {
    printf("YES\n1");
    return;
  }
  if (n == 2) {
    printf("YES\n1\n2");
    return;
  }
  if (n == 3) {
    printf("YES\n1\n2\n3");
    return;
  }
  if (n == 4) {
    printf("YES\n1\n3\n2\n4");
    return;
  }
  sieve(n);
  if (vis[n]) {
    printf("NO");
    return;
  }
  int phi = getphi(n), G = 0;
  for (int i = 1; i <= pn && prime[i] <= phi; ++i)
    if (phi % prime[i] == 0) ys[++tot] = prime[i];
  for (int i = 2; i < phi && !G; ++i) {
    bool g = 1;
    for (int j = 1; j <= tot && g; ++j)
      if (qpow(i, phi / ys[j], n) == 1) g = 0;
    if (g) G = i;
  }
  if (G) {
    printf("YES\n");
    for (int i = 0; i < (n - 1) / 2; ++i)
      Put(qpow(G, 2 * i, n), '\n'), Put(qpow(G, n - (2 * (i + 1)), n), '\n');
    Put(n);
  } else
    printf("NO");
}
int main() {
  n = Read();
  solve3();
  return 0;
}
