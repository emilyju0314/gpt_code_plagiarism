#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
}
int tag[800010], a[200010], n, m, q;
struct ha {
  int a[35];
};
ha xdt[800010], pdt[800010];
ha operator+(ha x, ha y) {
  ha c;
  for (int i = 0; i < (1 << m); ++i) c.a[i] = x.a[y.a[i]];
  return c;
}
void pd(int x, int l, int r) {
  if (l != r) {
    swap(xdt[x * 2], pdt[x * 2]);
    swap(xdt[x * 2 + 1], pdt[x * 2 + 1]);
    tag[x * 2] ^= 1;
    tag[x * 2 + 1] ^= 1;
  }
  tag[x] = 0;
}
void bd(int x, int l, int r) {
  if (l == r) {
    for (int i = 0; i < (1 << m); ++i)
      xdt[x].a[i] = (i >> 1), pdt[x].a[i] = (i >> 1);
    pdt[x].a[0] = (1 << (m - 1));
    if (a[l]) swap(xdt[x], pdt[x]);
  } else {
    int mid = (l + r) / 2;
    bd(x * 2, l, mid);
    bd(x * 2 + 1, mid + 1, r);
    xdt[x] = xdt[x * 2] + xdt[x * 2 + 1];
    pdt[x] = pdt[x * 2] + pdt[x * 2 + 1];
  }
}
void modify(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr)
    swap(xdt[x], pdt[x]), tag[x] ^= 1;
  else {
    int mid = (l + r) / 2;
    if (tag[x]) pd(x, l, r);
    if (rr <= mid)
      modify(x * 2, l, mid, ll, rr);
    else if (ll > mid)
      modify(x * 2 + 1, mid + 1, r, ll, rr);
    else
      modify(x * 2, l, mid, ll, rr), modify(x * 2 + 1, mid + 1, r, ll, rr);
    xdt[x] = xdt[x * 2] + xdt[x * 2 + 1];
    pdt[x] = pdt[x * 2] + pdt[x * 2 + 1];
  }
}
ha qy(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr)
    return xdt[x];
  else {
    if (tag[x]) pd(x, l, r);
    int mid = (l + r) / 2;
    if (rr <= mid)
      return qy(x * 2, l, mid, ll, rr);
    else if (ll > mid)
      return qy(x * 2 + 1, mid + 1, r, ll, rr);
    else
      return qy(x * 2, l, mid, ll, rr) + qy(x * 2 + 1, mid + 1, r, ll, rr);
  }
}
int main() {
  read(n);
  read(m);
  read(q);
  for (int i = 1; i <= n; ++i) read(a[i]), a[i] &= 1;
  bd(1, 1, n);
  for (int i = 1; i <= q; ++i) {
    int opt, l, r, d;
    read(opt);
    read(l);
    read(r);
    if (opt == 1) {
      read(d);
      d &= 1;
      if (d) modify(1, 1, n, l, r);
    } else {
      ha xx = qy(1, 1, n, l, r);
      if (xx.a[0] & (1 << (m - 1)))
        puts("2");
      else
        puts("1");
    }
  }
  return 0;
}
