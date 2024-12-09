#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, N = 100010;
struct Q {
  int l, w, id;
};
Q b[N];
int n, m, a[N], ans[N], num = 0;
inline int read() {
  int z = 0, base = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') c = getchar(), base = -1;
  while (c >= '0' && c <= '9') z = z * 10 + c - '0', c = getchar();
  return z * base;
}
inline bool comp(Q x, Q y) { return x.l < y.l; }
inline int power(int x, int k) {
  int z = 1;
  for (; k; x = (long long)x * x % P, k >>= 1)
    if (k & 1) z = (long long)z * x % P;
  return z % P;
}
namespace LB {
int p[65];
inline void ins(int x) {
  for (register int i = 60; i >= 0; --i) {
    if ((1LL << i) & x) {
      if (!p[i]) {
        p[i] = x, ++num;
        break;
      } else if (!(x ^= p[i]))
        break;
    }
  }
}
inline bool check(int x) {
  for (register int i = 60; i >= 0; --i)
    if ((1LL << i) & x) x ^= p[i];
  if (!x)
    return true;
  else
    return false;
}
}  // namespace LB
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  for (register int i = 1; i <= m; ++i) b[i] = (Q){read(), read(), i};
  sort(b + 1, b + m + 1, comp);
  using namespace LB;
  int cur = 1;
  for (register int i = 1; i <= m; ++i) {
    int l = b[i].l;
    for (; cur <= l; ++cur) LB::ins(a[cur]);
    if (LB::check(b[i].w)) ans[b[i].id] = power(2, l - num);
  }
  for (register int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}
