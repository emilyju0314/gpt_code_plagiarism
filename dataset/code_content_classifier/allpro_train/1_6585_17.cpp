#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int iv2 = (mod + 1) >> 1;
inline int MOD(int x) { return x >= mod ? x - mod : x; }
int qpow(int a, int b) {
  int as = 1;
  for (; b; a = 1ll * a * a % mod, b >>= 1)
    if (b & 1) as = 1ll * as * a % mod;
  return as;
}
struct r_e_d {
  inline int gti() {
    int x = 0, w = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
      x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * w;
  }
  inline long long gtl() {
    long long x = 0, w = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
      x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * w;
  }
  inline string gts() {
    string S;
    char ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
    while (ch != ' ' && ch != '\n' && ch != '\r')
      S.push_back(ch), ch = getchar();
    return S;
  }
} RD;
long long last_ans;
int rt, n, m, CT, lb[100005], lt;
struct treap {
  int zi[10000005], ch[10000005][2], sz[10000005], tt;
  int COP(int nw) {
    ++tt;
    zi[tt] = zi[nw];
    ch[tt][0] = ch[nw][0];
    ch[tt][1] = ch[nw][1];
    sz[tt] = sz[nw];
    return tt;
  }
  int NEW(int w) {
    ++tt;
    zi[tt] = w;
    sz[tt] = 1;
    ch[tt][0] = ch[tt][1] = 0;
    return tt;
  }
  void upd(int nw) {
    if (nw == 0) return;
    sz[nw] = sz[ch[nw][0]] + sz[ch[nw][1]] + 1;
  }
  void spt(int nw, int &a, int &b, int lm) {
    if (nw == 0) {
      a = b = 0;
      return;
    }
    ++CT;
    if (sz[ch[nw][0]] + 1 <= lm) {
      a = COP(nw);
      spt(ch[nw][1], ch[a][1], b, lm - sz[ch[nw][0]] - 1);
      upd(a);
    } else {
      b = COP(nw);
      spt(ch[nw][0], a, ch[b][0], lm);
      upd(b);
    }
  }
  void mrg(int &nw, int a, int b) {
    if (a * b == 0) {
      nw = COP(a + b);
      return;
    }
    ++CT;
    if ((rand() & 1) &&
        (1.0 * rand() / RAND_MAX <= 1.0 * sz[a] / (sz[a] + sz[b]))) {
      nw = COP(a);
      mrg(ch[nw][1], ch[a][1], b);
    } else {
      nw = COP(b);
      mrg(ch[nw][0], a, ch[b][0]);
    }
    upd(nw);
  }
  void dfs(int nw) {
    if (nw == 0) return;
    dfs(ch[nw][0]);
    lb[++lt] = zi[nw];
    dfs(ch[nw][1]);
    return;
  }
  void build(int &nw, int l, int r) {
    if (l > r) return;
    int md = (l + r) >> 1;
    nw = NEW(lb[md]);
    build(ch[nw][0], l, md - 1);
    build(ch[nw][1], md + 1, r);
    upd(nw);
  }
  void work(int i) {
    int x = 0, y = 0, z = 0, w = 0;
    int l = (1 + i - 1) % n + 1;
    int r = (m + i - 1) % n + 1;
    CT = 0;
    if (r < l) {
      spt(rt, w, x, l - 1);
      spt(w, z, w, r);
      mrg(x, x, z);
    } else {
      spt(rt, w, x, l - 1);
      spt(x, x, w, r - l + 1);
    }
    l = (m + 1 - i - 1 + n) % n + 1;
    r = (n - i - 1 + n) % n + 1;
    if (r < l) {
      spt(rt, w, y, l - 1);
      spt(w, z, w, r);
      mrg(y, y, z);
    } else {
      spt(rt, w, y, l - 1);
      spt(y, y, w, r - l + 1);
    }
    mrg(rt, x, y);
  }
} TP;
int f[55][100005];
long long t;
int s, la, op, wz, w, l, r;
int main() {
  n = RD.gti();
  m = RD.gti();
  s = RD.gti();
  t = RD.gtl();
  for (int i = (1); i <= (n); ++i) lb[i] = i;
  TP.build(rt, 1, n);
  for (int i = (1); i <= (n); ++i) {
    if (i % 1000 == 0) {
      lt = 0;
      TP.dfs(rt);
      rt = TP.tt = 0;
      TP.build(rt, 1, n);
    }
    TP.work(i);
  }
  while (t % n) {
    if (s <= m) {
      s = (s + (t % n) - 1 + n) % n + 1;
    } else {
      s = (s - (t % n) - 1 + n) % n + 1;
    }
    --t;
  }
  lt = 0;
  TP.dfs(rt);
  for (int i = (1); i <= (n); ++i) f[0][i] = lb[i];
  for (int i = (1); i <= (50); ++i)
    for (int nw = (1); nw <= (n); ++nw) f[i][nw] = f[i - 1][f[i - 1][nw]];
  long long K = t / n;
  int ct = 0;
  while (K) {
    if (K & 1) s = f[ct][s];
    ++ct;
    K >>= 1;
  }
  cout << s << endl;
  return 0;
}
