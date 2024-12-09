#include <bits/stdc++.h>
const int N = (1 << 20) + 10;
const int M = 9699690;
const int mod = 998244353, Gi = 332748118;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
using std::pair;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
int random(int i) { return rand() % i + 1; }
template <class T>
void ckmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void ckmin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
inline int plus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qp(int d, int k) {
  int f = 1;
  while (k) {
    if (k & 1) f = (1ll * (f) * (d) % mod);
    d = (1ll * (d) * (d) % mod), k >>= 1;
  }
  return f;
}
int n, in[N], turn[N];
void NTT(int *a, int typ, int len) {
  int L = -1;
  for (int i = 1; i < len; i <<= 1) ++L;
  for (int i = (1); i <= (len - 1); i++) {
    turn[i] = turn[i >> 1] >> 1 | (i & 1) << L;
    if (i < turn[i]) std::swap(a[i], a[turn[i]]);
  }
  for (int le = 1; le < len; le <<= 1) {
    int wn = qp(typ ? 3 : Gi, (mod - 1) / (le << 1));
    for (int p = 0; p < len; p += le << 1) {
      int w = 1;
      for (int i = p; i < p + le; i++, w = (1ll * (w) * (wn) % mod)) {
        int tx = a[i], ty = (1ll * (w) * (a[i + le]) % mod);
        a[i] = plus(tx, ty);
        a[i + le] = plus(tx, mod - ty);
      }
    }
  }
  if (!typ) {
    int inv = qp(len, mod - 2);
    for (int i = 0; i < len; i++) a[i] = (1ll * (a[i]) * (inv) % mod);
  }
}
std::vector<int> fv[N];
int a[N], b[N], fac[N];
std::priority_queue<pair<int, int> > q;
void fmul(int x1, int x2) {
  int s1 = fv[x1].size(), s2 = fv[x2].size();
  int len = 1;
  while (len < s1 + s2 - 1) len <<= 1;
  for (int i = (0); i <= (len - 1); i++) a[i] = b[i] = 0;
  for (int i = (0); i <= (s1 - 1); i++) a[i] = fv[x1][i];
  for (int i = (0); i <= (s2 - 1); i++) b[i] = fv[x2][i];
  NTT(a, 1, len), NTT(b, 1, len);
  for (int i = (0); i <= (len - 1); i++) a[i] = (1ll * (a[i]) * (b[i]) % mod);
  NTT(a, 0, len);
  fv[x1].clear();
  for (int i = (0); i <= (len - 1); i++) fv[x1].push_back(a[i]);
}
void work() {
  read(n);
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    read(u), read(v);
    ++in[u], ++in[v];
  }
  fac[0] = 1;
  ++in[1];
  for (int i = (1); i <= (n); i++) {
    fac[i] = (1ll * (fac[i - 1]) * (i) % mod);
    fv[i].push_back(1);
    if (in[i] != 1) fv[i].push_back(in[i] - 1);
    q.push(std::make_pair(-fv[i].size(), i));
  }
  while (q.size() > 1) {
    int p1 = q.top().second;
    q.pop();
    int p2 = q.top().second;
    q.pop();
    fmul(p2, p1);
    q.push(std::make_pair(-fv[p2].size(), p2));
  }
  int p = q.top().second, ans = 0;
  for (int i = (0); i <= (std::min((int)(fv[p].size()), n) - 1); i++) {
    if (i & 1)
      ans = plus(ans, (1ll * ((1ll * (fac[n - i]) * (mod - 1) % mod)) *
                       (fv[p][i]) % mod));
    else
      ans = plus(ans, (1ll * (fac[n - i]) * (fv[p][i]) % mod));
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  while (T--) work();
  return 0;
}
