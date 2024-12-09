#include <bits/stdc++.h>
using namespace std;
namespace jenga {
inline char get_unempty_char() {
  char ch;
  while (isspace(ch = getchar()))
    ;
  return ch;
}
const double eps(1e-12), Inf = 1e+64;
const int RED = 1, BLUE = 2, GREEN = 3, EMPTY = 0, N = 6, Base = 67,
          mod = 3000007;
int n, last[mod] = {}, next[mod] = {}, total_edge = 0, s[N * 3 - 1] = {},
       tot = 0;
unsigned long long hv[mod] = {};
double f[mod] = {};
inline void add(unsigned long long hash, double v) {
  int u = hash % mod;
  next[++total_edge] = last[u];
  last[u] = total_edge;
  f[total_edge] = v;
  hv[total_edge] = hash;
}
inline int get_num(char ch) {
  if (ch == 'R') return RED;
  if (ch == 'B') return BLUE;
  if (ch == 'G') return GREEN;
  if (ch == 'E') return EMPTY;
  assert(false);
}
void init() {
  n = get_unempty_char() - '0';
  for (int i = 1; i <= n; ++i) {
    s[i] |= get_num(get_unempty_char()) << 0;
    s[i] |= get_num(get_unempty_char()) << 2;
    s[i] |= get_num(get_unempty_char()) << 4;
  }
  tot = n;
}
inline unsigned long long hash(int *s, int k, int up) {
  static int v[N * 3 + 10] = {};
  unsigned long long h = 0;
  int tot = 0;
  for (int i = 1; i <= k; ++i) {
    int c1 = (s[i] >> 4) & 3, c2 = (s[i]) & 3, c3 = (s[i] >> 2) & 3;
    v[++tot] =
        c1 > c2 ? (c3 << 2) | c1 | (c2 << 4) : (c3 << 2) | c2 | (c1 << 4);
  }
  sort(v + 1, v + tot + 1);
  int c1 = (up >> 4) & 3, c2 = up & 3, c3 = (up >> 2) & 3;
  if (c1 > c2) up = c1 | (c2 << 4) | (c3 << 2);
  for (int i = 1; i <= tot; ++i)
    if (v[i]) h = (h << 6) + v[i];
  h = h * Base + up;
  return h;
}
double work(int *s, int tot, int up) {
  unsigned long long h = hash(s, tot, up);
  for (int i = last[h % mod]; i; i = next[i])
    if (hv[i] == h) return f[i];
  double v[4] = {Inf, Inf, Inf, Inf};
  int to = tot, D = 6;
  if ((up & 3) && ((up >> 2) & 3) && ((up >> 4) & 3)) s[++to] = up, up = 0;
  for (int i = 1; i <= tot; ++i) {
    int c1 = s[i] & 3, c2 = (s[i] >> 2) & 3, c3 = (s[i] >> 4) & 3, ns = s[i];
    if (c1 && c2 && c3 && v[c2] > eps) {
      s[i] = 0;
      if (!(up & 3))
        v[c2] = min(v[c2], work(s, to, up | c2));
      else if (!(up >> 4 & 3))
        v[c2] = min(v[c2], work(s, to, up | c2 << 4));
      if (!(up >> 2 & 3)) v[c2] = min(v[c2], work(s, to, up | c2 << 2));
      s[i] = ns;
    }
    if (c1 && c2 && v[c1] > eps) {
      s[i] = c3 == 0 ? 0 : s[i] & ~3;
      if (!(up & 3))
        v[c1] = min(v[c1], work(s, to, up | c1));
      else if (!(up >> 4 & 3))
        v[c1] = min(v[c1], work(s, to, up | c1 << 4));
      if (!(up >> 2 & 3)) v[c1] = min(v[c1], work(s, to, up | c1 << 2));
      s[i] = ns;
    }
    if (c2 && c3 && v[c3] > eps) {
      s[i] = c1 == 0 ? 0 : s[i] & ~48;
      if (!(up & 3))
        v[c3] = min(v[c3], work(s, to, up | c3));
      else if (!(up >> 4 & 3))
        v[c3] = min(v[c3], work(s, to, up | c3 << 4));
      if (!(up >> 2 & 3)) v[c3] = min(v[c3], work(s, to, up | c3 << 2));
      s[i] = ns;
    }
  }
  double sum = 0;
  if (v[1] != Inf) sum += v[1], D -= 1;
  if (v[2] != Inf) sum += v[2] * 2, D -= 2;
  if (v[3] != Inf) sum += v[3] * 2, D -= 2;
  sum = D == 6 ? 0 : (sum + 6) / (6 - D);
  add(h, sum);
  return sum;
}
int Main() {
  init();
  printf("%.15f\n", work(s, tot - 1, s[tot]));
  return 0;
}
}  // namespace jenga
int main() {
  jenga::Main();
  return 0;
}
