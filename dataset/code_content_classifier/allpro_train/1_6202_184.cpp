#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 1e9 + 7;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
template <typename A, typename B>
inline void read(A &x, B &y) {
  read(x);
  read(y);
}
template <typename A, typename B, typename C>
inline void read(A &x, B &y, C &z) {
  read(x);
  read(y);
  read(z);
}
template <typename A, typename B, typename C, typename D>
inline void read(A &x, B &y, C &z, D &w) {
  read(x);
  read(y);
  read(z);
  read(w);
}
template <typename A, typename B>
inline A fexp(A x, B p) {
  A ans = 1;
  for (; p; p >>= 1, x = 1LL * x * x % mod)
    if (p & 1) ans = 1LL * ans * x % mod;
  return ans;
}
template <typename A, typename B>
inline A fexp(A x, B p, A mo) {
  A ans = 1;
  for (; p; p >>= 1, x = 1LL * x * x % mo)
    if (p & 1) ans = 1LL * ans * x % mo;
  return ans;
}
int n, m, q, cnt;
int p[1010];
int A[maxn], OK[maxn];
int Exp(int x, int p) {
  int ans = 1;
  for (; p; p >>= 1, x *= x)
    if (p & 1) ans *= x;
  return ans;
}
int Exp(int x, int p, int m) {
  int ans = 1;
  for (; p; p >>= 1, x = 1ll * x * x % m)
    if (p & 1) ans = 1ll * ans * x % m;
  return ans;
}
bool Big(int x, int p, int m) {
  int ans = 1, ok = 0, okx = (x >= m);
  while (p) {
    if (p & 1) {
      if (okx) ok = 1;
      if (1ll * ans * x >= m) ok = 1;
      ans = 1ll * ans * x % m;
    }
    if (1ll * x * x >= m) okx = 1;
    x = 1ll * x * x % m;
    p >>= 1;
  }
  return ok;
}
int phi(int p) {
  int ans = 1;
  int m = (int)sqrt(p + .5);
  for (int i = (2); i <= (m); i++)
    if (p % i == 0) {
      ans *= i - 1;
      p /= i;
      while (p % i == 0) p /= i, ans *= i;
    }
  if (p > 1) ans *= p - 1;
  return ans;
}
int query(int l, int r, int now) {
  if (now == cnt) return 1;
  if (l == r) return A[l] < p[now] ? A[l] : A[l] % p[now] + p[now];
  int y = query(l + 1, r, now + 1);
  int x = A[l];
  bool ok = Big(x, y, p[now]);
  OK[l] = ok;
  if (!ok)
    return Exp(x, y);
  else
    return Exp(x, y, p[now]) + p[now];
}
void Work() {
  read(q);
  while (q--) {
    int l, r;
    read(l, r);
    printf("%d\n", query(l, r, 0) % p[0]);
  }
}
void Init() {
  read(n, p[0]);
  for (int i = (0); i <= (1000); i++) {
    if (p[i] == 1) {
      cnt = i;
      break;
    }
    p[i + 1] = phi(p[i]);
  }
  for (int i = (1); i <= (n); i++) read(A[i]);
}
int main() {
  Init();
  Work();
  return 0;
}
