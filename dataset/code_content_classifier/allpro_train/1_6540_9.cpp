#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
long long sandal[200009], ergen[200009], aydilge[200009], ceceli[200009],
    ekici[200009], n;
struct LazywithSegmentTree {
  long long s[200009 << 2], lazy[200009 << 2];
  void upd(int nd, int x, int y, long long v) {
    s[nd] = (y - x + 1) * v * 1LL;
    lazy[nd] = v;
  }
  void shift(int nd, int x, int y) {
    if (!lazy[nd]) return;
    int mid = (x + y) >> 1;
    upd(nd << 1, x, mid, lazy[nd]);
    upd(nd << 1 | 1, mid + 1, y, lazy[nd]);
    lazy[nd] = 0;
  }
  void build(int nd, int x, int y) {
    if (x == y) {
      s[nd] = sandal[x];
      return;
    }
    int mid = (x + y) >> 1;
    build(nd << 1, x, mid);
    build(nd << 1 | 1, mid + 1, y);
    s[nd] = s[nd << 1 | 1] + s[nd << 1];
  }
  long long tap(int l, int r, int nd, int x, int y) {
    if (l > y or x > r) return 0LL;
    if (l <= x and y <= r) return s[nd];
    shift(nd, x, y);
    int mid = (x + y) >> 1;
    long long i1 = tap(l, r, nd << 1, x, mid);
    long long i2 = tap(l, r, nd << 1 | 1, mid + 1, y);
    return i1 + i2;
  }
  int bul(int p, int nd, int x, int y) {
    if (x == y) return s[nd];
    shift(nd, x, y);
    int mid = (x + y) >> 1;
    if (p <= mid)
      return bul(p, nd << 1, x, mid);
    else
      return bul(p, nd << 1 | 1, mid + 1, y);
  }
  void modi(int l, int r, int v, int nd, int x, int y) {
    if (l > y or x > r) return;
    if (l <= x and y <= r) {
      upd(nd, x, y, v);
      return;
    }
    shift(nd, x, y);
    int mid = (x + y) >> 1;
    modi(l, r, v, nd << 1, x, mid);
    modi(l, r, v, nd << 1 | 1, mid + 1, y);
    s[nd] = s[nd << 1] + s[nd << 1 | 1];
  }
} T;
vector<long long> dv[200009];
void yener(int x, int y, long long v) {
  int st = x;
  while (x < y) {
    int mid = (x + y) >> 1;
    if (x == mid) mid++;
    if (T.bul(mid, 1, 1, n) <= v)
      x = mid;
    else
      y = mid - 1;
  }
  if (T.bul(y, 1, 1, n) <= v) {
    T.modi(st, y, v, 1, 1, n);
  } else if (T.bul(x, 1, 1, n) <= v) {
    T.modi(st, x, v, 1, 1, n);
  }
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", ergen + i);
  for (int i = 1; i < 200009; i++)
    for (int j = i; j < 200009; j += i) ekici[j]++;
  for (int i = 1; i < 200009; i++) dv[i].resize(ekici[i]);
  memset(ekici, 0, sizeof(ekici));
  for (int i = 1; i < 200009; i++)
    for (int j = i; j < 200009; j += i) dv[j][ekici[j]++] = i;
  memset(aydilge, 0, sizeof(aydilge));
  memset(ceceli, -1, sizeof ceceli);
  for (int i = 1; i <= n; i++) {
    sandal[i] = sandal[i - 1];
    for (typeof((dv[ergen[i]]).begin()) it = (dv[ergen[i]]).begin();
         it != (dv[ergen[i]]).end(); it++) {
      aydilge[*it]++;
      if (aydilge[*it] == 1) ceceli[*it] = i;
      if (aydilge[*it] == 2) umax(sandal[i], *it);
    }
  }
  T.build(1, 1, n);
  long long boz = 0, ortac = 0;
  memset(aydilge, 0, sizeof(aydilge));
  for (int i = n; i >= 1; i--) {
    boz += T.tap(1, i - 1, 1, 1, n) + ortac;
    for (typeof((dv[ergen[i]]).begin()) it = (dv[ergen[i]]).begin();
         it != (dv[ergen[i]]).end(); it++) {
      aydilge[*it]++;
      if (aydilge[*it] == 2) umax(ortac, *it);
      if (~ceceli[*it]) {
        yener(ceceli[*it], i - 1, *it);
        ceceli[*it] = -1;
      }
    }
    yener(1, i - 1, ortac);
  }
  printf("%lld\n", boz);
  return 0;
}
