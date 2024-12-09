#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 1010, D = 32;
int i, j, k, n, m, q, o, x, y, ch, Pn, En;
int a[N], h[N], l[N], r[N], p[N], Cnt[65536];
struct Bitset {
  unsigned int a[D];
  int count() {
    int i, cnt = 0;
    for (i = 0; i < D; i += 4) {
      cnt += Cnt[a[i] >> 16] + Cnt[a[i] & 65535];
      cnt += Cnt[a[i + 1] >> 16] + Cnt[a[i + 1] & 65535];
      cnt += Cnt[a[i + 2] >> 16] + Cnt[a[i + 2] & 65535];
      cnt += Cnt[a[i + 3] >> 16] + Cnt[a[i + 3] & 65535];
    }
    return cnt;
  }
  void clear() { memset(a, 0, sizeof a); }
  void up(const Bitset &x, const Bitset &y) {
    for (int i = 0; i < D; i += 4) {
      a[i] = x.a[i] | y.a[i];
      a[i + 1] = x.a[i + 1] | y.a[i + 1];
      a[i + 2] = x.a[i + 2] | y.a[i + 2];
      a[i + 3] = x.a[i + 3] | y.a[i + 3];
    }
  }
  void operator|=(const int &n) { a[n >> 5] |= 1u << (n & 31); }
  void operator|=(const Bitset &n) {
    for (int i = 0; i < D; i += 4) {
      a[i] |= n.a[i];
      a[i + 1] |= n.a[i + 1];
      a[i + 2] |= n.a[i + 2];
      a[i + 3] |= n.a[i + 3];
    }
  }
  void operator&=(const Bitset &n) {
    for (int i = 0; i < D; i += 4) {
      a[i] &= n.a[i];
      a[i + 1] &= n.a[i + 1];
      a[i + 2] &= n.a[i + 2];
      a[i + 3] &= n.a[i + 3];
    }
  }
  void operator+=(int n) {
    Bitset t;
    t = *this;
    clear();
    int x = n >> 5, y = n & 31, z = 32 - y, i;
    if (!y) {
      for (i = 0; x + i + 3 < D; i += 4) {
        a[x + i] |= t.a[i];
        a[x + i + 1] |= t.a[i + 1];
        a[x + i + 2] |= t.a[i + 2];
        a[x + i + 3] |= t.a[i + 3];
      }
      for (; x + i < D; i++) a[x + i] |= t.a[i];
    } else {
      a[x] |= t.a[0] << y;
      for (i = 1; x + i + 3 < D; i += 4) {
        a[x + i] |= t.a[i] << y | t.a[i - 1] >> z;
        a[x + i + 1] |= t.a[i + 1] << y | t.a[i] >> z;
        a[x + i + 2] |= t.a[i + 2] << y | t.a[i + 1] >> z;
        a[x + i + 3] |= t.a[i + 3] << y | t.a[i + 2] >> z;
      }
      for (; x + i < D; i++) a[x + i] |= t.a[i] << y | t.a[i - 1] >> z;
    }
    n = m - n;
    x = n >> 5, y = n & 31, z = 32 - y;
    if (!y) {
      for (i = 0; x + i + 3 < D; i += 4) {
        a[i] |= t.a[x + i];
        a[i + 1] |= t.a[x + i + 1];
        a[i + 2] |= t.a[x + i + 2];
        a[i + 3] |= t.a[x + i + 3];
      }
      for (; x + i < D; i++) a[i] |= t.a[x + i];
    } else {
      for (i = 0; x + i + 4 < D; i += 4) {
        a[i] |= t.a[x + i] >> y | t.a[x + i + 1] << z;
        a[i + 1] |= t.a[x + i + 1] >> y | t.a[x + i + 2] << z;
        a[i + 2] |= t.a[x + i + 2] >> y | t.a[x + i + 3] << z;
        a[i + 3] |= t.a[x + i + 3] >> y | t.a[x + i + 4] << z;
      }
      for (; x + i + 1 < D; i++) a[i] |= t.a[x + i] >> y | t.a[x + i + 1] << z;
      a[i] |= t.a[x + i] >> y;
    }
  }
} pr, Ans;
struct tree {
  int ad;
  Bitset Bit;
} T[N << 2];
struct edge {
  int s, n;
} E[N << 1];
void R(int &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void W(int x) {
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
void pre(int m) {
  for (int i = 2, j; i < m; i++) {
    for (j = 2; j * j <= i; j++)
      if (i % j == 0) break;
    if (j * j > i) pr |= i;
  }
  for (int i = 0; i < 65536; i++) {
    int j = i;
    while (j) Cnt[i] += j & 1, j >>= 1;
  }
}
void E_add(int x, int y) {
  E[++En].s = y;
  E[En].n = h[x];
  h[x] = En;
  E[++En].s = x;
  E[En].n = h[y];
  h[y] = En;
}
void dfs(int x, int F) {
  l[x] = ++Pn;
  p[Pn] = x;
  for (int k = h[x]; k; k = E[k].n)
    if (E[k].s != F) dfs(E[k].s, x);
  r[x] = Pn;
}
void down(int k) {
  if (T[k].ad) {
    T[k << 1].ad = (T[k << 1].ad + T[k].ad) % m;
    T[k << 1 | 1].ad = (T[k << 1 | 1].ad + T[k].ad) % m;
    T[k << 1].Bit += T[k].ad;
    T[k << 1 | 1].Bit += T[k].ad;
    T[k].ad = 0;
  }
}
void T_build(int L, int R, int k) {
  if (L == R) {
    T[k].ad = 0;
    T[k].Bit |= a[p[L]];
    return;
  }
  int mid = (L + R) >> 1;
  T_build(L, mid, k << 1);
  T_build(mid + 1, R, k << 1 | 1);
  T[k].Bit.up(T[k << 1].Bit, T[k << 1 | 1].Bit);
}
void T_add(int L, int R, int l, int r, int ad, int k) {
  if (L == l && R == r) {
    T[k].ad = (T[k].ad + ad) % m;
    T[k].Bit += ad;
    return;
  }
  down(k);
  int mid = (L + R) >> 1;
  if (r <= mid)
    T_add(L, mid, l, r, ad, k << 1);
  else {
    if (l > mid)
      T_add(mid + 1, R, l, r, ad, k << 1 | 1);
    else
      T_add(L, mid, l, mid, ad, k << 1),
          T_add(mid + 1, R, mid + 1, r, ad, k << 1 | 1);
  }
  T[k].Bit.up(T[k << 1].Bit, T[k << 1 | 1].Bit);
}
void T_query(int L, int R, int l, int r, int k) {
  if (L == l && R == r) {
    Ans |= T[k].Bit;
    return;
  }
  down(k);
  int mid = (L + R) >> 1;
  if (r <= mid)
    T_query(L, mid, l, r, k << 1);
  else {
    if (l > mid)
      T_query(mid + 1, R, l, r, k << 1 | 1);
    else
      T_query(L, mid, l, mid, k << 1),
          T_query(mid + 1, R, mid + 1, r, k << 1 | 1);
  }
}
int main() {
  R(n);
  R(m);
  pre(m);
  for (i = 1; i <= n; i++) R(a[i]), a[i] %= m;
  for (i = 1; i < n; i++) R(x), R(y), E_add(x, y);
  dfs(1, 0);
  T_build(1, n, 1);
  R(q);
  for (i = 1; i <= q; i++) {
    R(o);
    if (o == 1)
      R(x), R(y), T_add(1, n, l[x], r[x], y % m, 1);
    else {
      Ans.clear();
      R(x);
      T_query(1, n, l[x], r[x], 1);
      Ans &= pr;
      W(Ans.count()), puts("");
    }
  }
}
