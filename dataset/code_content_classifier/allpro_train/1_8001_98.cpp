#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  static long long x, f;
  static char c;
  x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const long long N = 200050;
long long n, len;
long long S, ans;
struct Data {
  long long a, b;
  bool operator<(const Data w) const {
    if (b != w.b) return b < w.b;
    return a < w.a;
  }
} a[N], b[N];
struct data {
  long long tim, money;
  inline void init(long long t, long long m) { tim = t, money = m; }
  bool operator<(const data w) const {
    return (tim == w.tim) ? (money < w.money) : (tim > w.tim);
  }
  bool operator>(const data w) const {
    return (tim == w.tim) ? (money > w.money) : (tim < w.tim);
  }
} dp[N], tmp;
long long fr[N];
long long Q[N], ql, qr, tl[N], tr[N];
data get(long long j, long long i) {
  static data tmp;
  static long long nt, nm;
  if (dp[j].money <= a[i].a) {
    nt = dp[j].tim + (a[i].a - dp[j].money) / a[j].b +
         ((a[i].a - dp[j].money) % a[j].b ? 1 : 0);
    nm = -a[i].a + (nt - dp[j].tim) * a[j].b + dp[j].money;
    tmp.init(nt, nm);
    return tmp;
  }
  nt = dp[j].tim;
  nm = dp[j].money - a[i].a;
  tmp.init(nt, nm);
  return tmp;
}
signed main() {
  long long i, j, nt, nm, ll, rr, L, R, Mid, Ans;
  n = read(), S = read();
  ans = S * 2 + 5;
  for (i = 1; i <= n; ++i) a[i].b = read(), a[i].a = read();
  sort(a + 1, a + n + 1);
  for (len = 0, i = 1; i <= n; ++i)
    if (i == 1 || a[i].b != a[i - 1].b) b[++len] = a[i];
  for (n = len, i = 1; i <= n; ++i) a[i] = b[i];
  for (len = 0, i = 1; i <= n; ++i) {
    while (len && a[i].a <= b[len].a) --len;
    b[++len] = a[i];
  }
  for (n = len, i = 1; i <= n; ++i) a[i] = b[i];
  dp[1].init(0, 0), fr[1] = -1;
  Q[ql = qr = 1] = 1, tl[1] = 2, tr[1] = n;
  for (i = 2; i <= n; ++i) {
    while (ql <= qr && tr[ql] < i) ++ql;
    dp[i] = get(Q[ql], i);
    ll = n + 1, rr = n;
    while (ql <= qr && tr[ql] <= i) ++ql;
    while (ql <= qr && get(i, tr[qr]) > get(Q[qr], tr[qr])) {
      if (get(i, tl[qr]) > get(Q[qr], tl[qr])) {
        ll = tl[qr];
        --qr;
        continue;
      }
      L = tl[qr], R = tr[qr], Ans = R + 1;
      while (L <= R) {
        Mid = (L + R) >> 1;
        if (get(i, Mid) > get(Q[qr], Mid))
          Ans = Mid, R = Mid - 1;
        else
          L = Mid + 1;
      }
      ll = Ans;
      tr[qr] = Ans - 1;
      break;
    }
    if (ll <= rr) {
      Q[++qr] = i;
      tl[qr] = ll, tr[qr] = rr;
    }
  }
  for (i = 1; i <= n; ++i) {
    if (dp[i].money >= S) {
      ans = min(ans, dp[i].tim);
      continue;
    }
    ans = min(ans, dp[i].tim + (S - dp[i].money) / a[i].b +
                       ((S - dp[i].money) % a[i].b ? 1 : 0));
  }
  cout << ans << '\n';
  return 0;
}
