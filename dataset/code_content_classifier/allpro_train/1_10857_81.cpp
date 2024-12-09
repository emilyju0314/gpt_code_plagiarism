#include <bits/stdc++.h>
using namespace std;
int n;
char S[200006];
const int base = 137, ivb = 131276920;
const int P = 418254373;
int Pow(int x, int a) {
  int ret = 1;
  while (a) {
    if (a & 1) ret = ret * 1ll * x % P;
    x = x * 1ll * x % P, a >>= 1;
  }
  return ret;
}
char W[200006 << 1];
int len[200006];
void manacher() {
  for (int i = (1), iend = (n); i <= iend; ++i)
    W[i << 1] = S[i], W[i << 1 | 1] = '#';
  int N = n << 1 | 1;
  W[0] = '(', W[1] = '#', W[N + 1] = ')';
  int mx = 0, ps = 0;
  for (int i = (1), iend = (N); i <= iend; ++i) {
    len[i] = i > mx ? 1 : min(len[(ps << 1) - i], mx - i);
    while (W[i - len[i]] == W[i + len[i]]) ++len[i];
    if (i + len[i] > mx) mx = i + len[i], ps = i;
  }
}
int w[200006];
int has[200006];
int bs[200006], ib[200006];
int hs[200006], rhs[200006], pr[200006];
bool equa(int l, int r, int L, int R) {
  return (hs[r] - hs[l - 1] + P) * 1ll * ib[l - 1] % P ==
         (rhs[L] - rhs[R + 1] + P) * 1ll * ib[n - R] % P;
}
void solve() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  manacher();
  for (int i = (1), iend = (n); i <= iend; ++i) w[i] = len[i << 1] / 2 - 1;
  bs[0] = ib[0] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i)
    bs[i] = bs[i - 1] * 1ll * base % P, ib[i] = ib[i - 1] * 1ll * ivb % P;
  int cur = 1;
  for (int i = (1), iend = (n); i <= iend; ++i)
    hs[i] = (hs[i - 1] + S[i] * 1ll * bs[i]) % P;
  for (int i = (n), iend = (1); i >= iend; --i)
    rhs[i] = (rhs[i + 1] + S[i] * 1ll * bs[n - i + 1]) % P;
  for (int i = (n), iend = (1); i >= iend; --i) {
    int l = n - i + 1;
    while (cur <= n && (cur < l || !equa(i, n, cur - l + 1, cur))) ++cur;
    pr[n - i + 1] = cur;
  }
  int as = 0;
  int p1, l1, p2, l2, p3;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    int fr = i - w[i], tr = i + w[i];
    int s = (upper_bound(pr + 1, pr + 1 + n, fr - 1) - pr - 1);
    s = max(tr + 1, n - s + 1);
    if ((n - s + 1) * 2 + w[i] * 2 + 1 > as) {
      as = (n - s + 1) * 2 + w[i] * 2 + 1;
      p2 = i - w[i], l2 = w[i] * 2 + 1;
      if (s == n + 1) {
        p1 = p3 = 0;
      } else {
        l1 = n - s + 1;
        p1 = pr[n - s + 1] - l1 + 1, p3 = s;
      }
    }
  }
  if (!p1) {
    puts("1");
    cout << p2 << ' ' << l2 << endl;
  } else {
    puts("3");
    cout << p1 << ' ' << l1 << endl
         << p2 << ' ' << l2 << endl
         << p3 << ' ' << l1 << endl;
  }
}
signed main() { solve(); }
