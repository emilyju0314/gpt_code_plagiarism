#include <bits/stdc++.h>
using namespace std;
struct Hash {
  int p, w, f;
  inline void set(int _p, int _w, int _f) { p = _p, w = _w, f = _f; }
};
struct HashMap {
  Hash h[5000000 + 10];
  int hp[1000007], sz;
  inline void ins(int p, int w) {
    h[++sz].set(p, w, hp[p % 1000007]), hp[p % 1000007] = sz;
  }
  inline int find(int p) {
    for (int i = hp[p % 1000007]; i; i = h[i].f)
      if (h[i].p == p) return h[i].w;
    return -1;
  }
} ph, fid;
int li[20000], len, n, m, P, g, a[10100], inv_pow;
long long f[20000];
bool vis[20000];
inline int pr(int a, int z) {
  int s = 1;
  do {
    if (z & 1) s = 1ll * s * a % P;
    a = 1ll * a * a % P;
  } while (z >>= 1);
  return s;
}
inline bool check() {
  for (int i = 1; i <= len; ++i)
    if (li[i] < P - 1 && pr(g, li[i]) == 1) return false;
  return true;
}
inline int findG() {
  for (g = 2; !check(); ++g)
    ;
  return g;
}
template <class Z>
Z gcx(Z a, Z b) {
  return !b ? a : gcx(b, a % b);
}
inline int logg(int x) {
  int t;
  if ((t = ph.find(x)) != -1) return t;
  for (int i = 1; i <= 210; ++i) {
    x = 1ll * x * inv_pow % P;
    if ((t = ph.find(x)) != -1) return i * 5000000 + t;
  }
  assert(0);
}
void getFac(int n) {
  for (int i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    li[++len] = i;
    if (i * i != n) li[++len] = n / i;
  }
  sort(li + 1, li + len + 1);
  for (int i = 1; i <= len; ++i) fid.ins(li[i], i);
}
inline void init() {
  getFac(P - 1), findG();
  int tp = 1;
  for (int i = 0; i < 5000000; ++i) ph.ins(tp, i), tp = 1ll * tp * g % P;
  inv_pow = pr(tp, P - 2);
}
int calc() {
  f[1] = -1;
  for (int i = 1; i <= len; ++i) {
    if (!vis[i]) continue;
    for (int j = len; j >= 1; --j)
      f[fid.find(1ll * li[i] * li[j] / gcx(li[i], li[j]))] -= f[j];
  }
  f[1]++;
  int res = 0;
  for (int i = 1; i <= len; ++i) res += f[i] * (P - 1) / li[i];
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &P), init();
  int b, tb;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] = logg(a[i]);
  scanf("%d", &b);
  for (int i = 1; i <= m - 1; ++i) scanf("%d", &tb), b = gcx(tb, b);
  for (int i = 1; i <= n; ++i)
    vis[fid.find(gcx(1ll * a[i] * b, P - 1ll))] = true;
  printf("%d\n", calc());
  return 0;
}
