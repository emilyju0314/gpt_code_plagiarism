#include <bits/stdc++.h>
using namespace std;
namespace io {
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class I>
inline void fr(I &num) {
  num = 0;
  register char c = nc();
  register int p = 1;
  while (c < '0' || c > '9') c == '-' ? p = -1, c = nc() : c = nc();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = nc();
  num *= p;
}
};  // namespace io
using io ::fr;
const int N = 1000005;
int pw[N], hs[N][2], n, Q, s[N];
char S[N];
inline int que(const int l, const int r) {
  const int k = l & 1;
  return (hs[r][k] - (0ll + hs[l - 1][k]) * pw[s[r] - s[l - 1]] % 1000000007 +
          1000000007) %
         1000000007;
}
int main() {
  scanf("%d%s", &n, S + 1), pw[0] = 1;
  register int i, x, y;
  for (i = 1; i <= n; ++i)
    s[i] = s[i - 1] + (S[i] == '0'), pw[i] = 137ll * pw[i - 1] % 1000000007,
    S[i] == '1'
        ? hs[i][0] = hs[i - 1][0],
    hs[i][1] = hs[i - 1][1]
        : (hs[i][0] = (137ll * hs[i - 1][0] + (i & 1) + 37) % 1000000007,
           hs[i][1] = (137ll * hs[i - 1][1] + (!(i & 1)) + 37) % 1000000007);
  scanf("%d", &Q);
  while (Q--)
    scanf("%d%d%d", &x, &y, &i),
        que(x, x + i - 1) ^ que(y, y + i - 1) ? puts("No") : puts("Yes");
  return 0;
}
