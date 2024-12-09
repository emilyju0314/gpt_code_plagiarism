#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int maxn = 300005;
const int mn = maxn << 2;
int getint() {
  int r = 0, k = 1;
  char c = getchar();
  for (; '0' > c || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) r = r * 10 - '0' + c;
  return r * k;
}
int P[maxn], n, pos[maxn];
long long m1[mn], m2[mn], c1[mn], c2[mn], lazy[mn], ans = 0;
void add(int x, int v) {
  m1[x] += v;
  m2[x] += v;
  lazy[x] += v;
}
void pd(int now) {
  if (lazy[now]) {
    add(now << 1, lazy[now]);
    add(now << 1 | 1, lazy[now]);
    lazy[now] = 0;
  }
}
void pu(int x) {
  int L = x << 1, R = x << 1 | 1;
  if (m1[L] > m1[R]) swap(L, R);
  if (m1[L] < m1[R]) {
    m1[x] = m1[L];
    c1[x] = c1[L];
    if (m2[L] < m1[R]) {
      m2[x] = m2[L];
      c2[x] = c2[L];
    } else if (m2[L] == m1[R]) {
      m2[x] = m2[L];
      c2[x] = c2[L] + c1[R];
    } else {
      m2[x] = m1[R];
      c2[x] = c1[R];
    }
  }
  if (m1[L] == m1[R]) {
    m1[x] = m1[L];
    c1[x] = c1[L] + c1[R];
    if (m2[L] < m2[R]) {
      m2[x] = m2[L];
      c2[x] = c2[L];
    } else if (m2[R] < m2[L]) {
      m2[x] = m2[R];
      c2[x] = c2[R];
    } else {
      m2[x] = m2[R];
      c2[x] = c2[L] + c2[R];
    }
  }
}
void change(int now, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    add(now, v);
    return;
  }
  pd(now);
  int mid = (l + r) >> 1;
  if (ll <= mid) change(now << 1, l, mid, ll, rr, v);
  if (rr > mid) change(now << 1 | 1, mid + 1, r, ll, rr, v);
  pu(now);
}
void query(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    if (m1[x] == 1 || m1[x] == 2) ans += c1[x];
    if (m2[x] == 1 || m2[x] == 2) ans += c2[x];
    return;
  }
  pd(x);
  int mid = (l + r) >> 1;
  if (ll <= mid) query(x << 1, l, mid, ll, rr);
  if (rr > mid) query(x << 1 | 1, mid + 1, r, ll, rr);
}
void build(int x, int l, int r) {
  if (l == r) {
    c1[x] = 1;
    m2[x] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pu(x);
}
int main() {
  n = getint();
  for (int i = 1; i <= n; ++i) {
    P[i] = getint();
    pos[P[i]] = i;
  }
  build(1, 1, n);
  for (int l = n; l; --l) {
    int x = pos[l];
    if (l > P[x - 1] && l > P[x + 1]) change(1, 1, n, l, n, 1);
    if (l > P[x - 1] && l < P[x + 1]) change(1, 1, n, l, P[x + 1] - 1, 1);
    if (l < P[x - 1] && l > P[x + 1]) change(1, 1, n, l, P[x - 1] - 1, 1);
    if (l < P[x - 1] && l < P[x + 1]) {
      int L = P[x - 1], R = P[x + 1];
      if (L > R) swap(L, R);
      change(1, 1, n, l, L - 1, 1);
      change(1, 1, n, R, n, -1);
    }
    query(1, 1, n, l, n);
  }
  ans = ans - n;
  printf("%I64d", ans);
}
