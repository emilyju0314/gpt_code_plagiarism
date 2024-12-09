#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const long long oo = 1000000000000000000ll;
int ii, i, j, k, n, m, q, ch, En, o, x, y, Tn, nm, fx, fy, ans, tt;
int c[N], h[N], a[N], Ans[N];
vector<int> A[N];
struct cc {
  long long val;
  int x;
  bool operator<(const cc &n) const {
    if (val == n.val) return c[a[x]] < c[a[n.x]];
    return val < n.val;
  }
};
struct dd {
  int l, r;
  cc x;
} B[N];
struct edge {
  int s, n;
} E[N];
struct tree {
  long long ad;
  cc mi;
} T[N << 2];
struct point {
  int fa, sz, dp, sn, tp, l, r;
} P[N];
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
void E_add(int x, int y) {
  E[++En].s = y;
  E[En].n = h[x];
  h[x] = En;
  E[++En].s = x;
  E[En].n = h[y];
  h[y] = En;
}
void dfs1(int x, int F) {
  P[x].fa = F;
  P[x].dp = P[F].dp + 1;
  P[x].sz = 1;
  int ma = 0, k;
  for (k = h[x]; k; k = E[k].n)
    if (E[k].s != F) {
      dfs1(E[k].s, x);
      P[x].sz += P[E[k].s].sz;
      if (P[E[k].s].sz > P[P[x].sn].sz) P[x].sn = E[k].s;
    }
}
void dfs2(int x, int F, int top) {
  int k;
  P[x].tp = top;
  P[x].l = Tn + 1;
  for (k = 0; k < A[x].size(); k++) a[++Tn] = A[x][k];
  if (P[x].sn) dfs2(P[x].sn, x, top);
  for (k = h[x]; k; k = E[k].n)
    if (E[k].s != F && E[k].s != P[x].sn) dfs2(E[k].s, x, E[k].s);
  P[x].r = Tn;
}
void up(int k) { T[k].mi = min(T[k << 1].mi, T[k << 1 | 1].mi); }
void down(int k) {
  if (T[k].ad) {
    T[k << 1].ad += T[k].ad;
    T[k << 1].mi.val += T[k].ad;
    T[k << 1 | 1].ad += T[k].ad;
    T[k << 1 | 1].mi.val += T[k].ad;
    T[k].ad = 0;
  }
}
void T_build(int L, int R, int k) {
  if (L == R) {
    T[k].mi.val = a[L];
    T[k].mi.x = L;
    return;
  }
  int mid = (L + R) >> 1;
  T_build(L, mid, k << 1);
  T_build(mid + 1, R, k << 1 | 1);
  up(k);
}
cc T_query(int L, int R, int l, int r, int k) {
  if (L == l && R == r) return T[k].mi;
  down(k);
  int mid = (L + R) >> 1;
  if (r <= mid) return T_query(L, mid, l, r, k << 1);
  if (l > mid) return T_query(mid + 1, R, l, r, k << 1 | 1);
  return min(T_query(L, mid, l, mid, k << 1),
             T_query(mid + 1, R, mid + 1, r, k << 1 | 1));
}
void T_change(int L, int R, int x, int k) {
  if (L == R) {
    T[k].mi.val = oo;
    return;
  }
  down(k);
  int mid = (L + R) >> 1;
  if (x <= mid)
    T_change(L, mid, x, k << 1);
  else
    T_change(mid + 1, R, x, k << 1 | 1);
  up(k);
}
void T_add(int L, int R, int l, int r, int ad, int k) {
  if (L == l && R == r) {
    T[k].ad += ad;
    T[k].mi.val += ad;
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
  up(k);
}
int main() {
  R(n);
  R(m);
  R(q);
  for (i = 1; i < n; i++) {
    R(x);
    R(y);
    E_add(x, y);
  }
  for (i = 1; i <= m; i++) {
    R(c[i]);
    A[c[i]].push_back(i);
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  T_build(1, m, 1);
  for (ii = 1; ii <= q; ii++) {
    R(o);
    if (o == 1) {
      R(x);
      R(y);
      R(k);
      nm = 0;
      fx = P[x].tp;
      fy = P[y].tp;
      while (fx != fy) {
        if (P[fx].dp > P[fy].dp) {
          B[++nm].l = P[fx].l;
          B[nm].r = P[x].l + A[x].size() - 1;
          if (B[nm].l > B[nm].r) nm--;
          x = P[fx].fa;
          fx = P[x].tp;
        } else {
          B[++nm].l = P[fy].l;
          B[nm].r = P[y].l + A[y].size() - 1;
          if (B[nm].l > B[nm].r) nm--;
          y = P[fy].fa;
          fy = P[y].tp;
        }
      }
      if (P[x].dp < P[y].dp)
        B[++nm].l = P[x].l, B[nm].r = P[y].l + A[y].size() - 1;
      else
        B[++nm].l = P[y].l, B[nm].r = P[x].l + A[x].size() - 1;
      if (B[nm].l > B[nm].r) nm--;
      if (!nm) {
        puts("0");
        continue;
      }
      for (i = 1; i <= nm; i++) B[i].x = T_query(1, m, B[i].l, B[i].r, 1);
      ans = 0;
      while (k--) {
        tt = 1;
        for (i = 2; i <= nm; i++)
          if (B[i].x < B[tt].x) tt = i;
        if (B[tt].x.val >= oo) break;
        Ans[++ans] = a[B[tt].x.x];
        T_change(1, m, B[tt].x.x, 1);
        B[tt].x = T_query(1, m, B[tt].l, B[tt].r, 1);
      }
      W(ans);
      for (i = 1; i <= ans; i++) putchar(' '), W(Ans[i]);
      puts("");
    } else {
      R(x);
      R(k);
      if (P[x].l <= P[x].r) T_add(1, m, P[x].l, P[x].r, k, 1);
    }
  }
}
