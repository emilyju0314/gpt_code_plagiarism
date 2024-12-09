#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int d = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; d = d * 10 + c - 48, c = getchar())
    ;
  return d * f;
}
const int N = 1000010;
int n, m, k, pn, qn;
struct xint {
  int ti, x, c;
} p[N], q[N];
bool cmp(xint a, xint b) { return a.ti < b.ti; }
long long w1[N], w2[N], w[N];
int main() {
  n = read(), m = read(), k = read();
  k++;
  for (int i = 1; i <= m; ++i) {
    int a = read(), b = read(), c = read(), d = read();
    if (b == 0)
      q[++qn] = (xint){a, c, d};
    else
      p[++pn] = (xint){a, b, d};
  }
  sort(p + 1, p + pn + 1, cmp);
  sort(q + 1, q + qn + 1, cmp);
  int M = (int)1e6;
  for (int i = 1; i <= n; ++i) w[i] = (long long)1e12;
  for (int i = 1; i <= n; ++i) w1[0] += w[i];
  for (int i = 1, cnt = 1; i <= M; ++i) {
    w1[i] = w1[i - 1];
    while (cnt <= pn && p[cnt].ti <= i) {
      int po = p[cnt].x, pc = p[cnt].c;
      if (pc < w[po]) w1[i] -= w[po] - pc, w[po] = pc;
      ++cnt;
    }
  }
  for (int i = 1; i <= n; ++i) w[i] = (long long)1e12;
  for (int i = 1; i <= n; ++i) w2[M + 1] += w[i];
  for (int i = M, cnt = qn; i >= 1; --i) {
    w2[i] = w2[i + 1];
    while (cnt >= 1 && q[cnt].ti >= i) {
      int qo = q[cnt].x, qc = q[cnt].c;
      if (qc < w[qo]) w2[i] -= w[qo] - qc, w[qo] = qc;
      --cnt;
    }
  }
  long long ans = (long long)1e12;
  for (int i = 1; i <= M - k; ++i) ans = min(ans, w1[i] + w2[i + k]);
  if (ans >= (long long)1e12) ans = -1;
  printf("%lld\n", ans);
}
