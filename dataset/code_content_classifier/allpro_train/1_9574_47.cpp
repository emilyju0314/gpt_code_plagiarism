#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 - '0' + s;
    s = getchar();
  }
  return x * f;
}
inline long long qkmul(long long x, long long y, long long mod) {
  long long tmp =
      (x * y - (long long)((long double)x / mod * y + 1.0e-8) * mod);
  return tmp < 0 ? tmp + mod : tmp;
}
int n, m, i, j, s, o, k;
int a[200005];
map<int, int> pre;
map<int, int> nm;
inline int highbit(int x) {
  int l = 0, r = 30, mid;
  while (l ^ r) {
    mid = (l + r) >> 1;
    if ((1 << mid) > (x >> 1))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
struct it {
  int F[31], cnt;
  it() {
    memset(F, 0, sizeof(F));
    cnt = 0;
  }
  inline void ins(int x) {
    while (x) {
      int j = highbit(x);
      if (!F[j]) {
        F[j] = x;
        cnt++;
        return;
      }
      x ^= F[j];
    }
    return;
  }
};
int xxj[200005];
inline it operator+(it a, it b) {
  if (!a.cnt) return b;
  if (!b.cnt) return a;
  for (int i = 0; i <= 30; i++) a.ins(b.F[i]);
  return a;
}
it tre[200005 << 2];
int M;
inline void maketree(int n) {
  M = 1;
  while (M < n + 2) M <<= 1;
}
inline void addtree(int x, int y) {
  if (x > n) return;
  int s = M + x;
  tre[s] = it();
  tre[s].ins(y);
  s >>= 1;
  while (s) {
    tre[s] = tre[s << 1] + tre[s << 1 | 1];
    s >>= 1;
  }
}
inline it findtree(int l, int r) {
  int s = M + l - 1, t = M + r + 1;
  it ans;
  while (s || t) {
    if ((s >> 1) ^ (t >> 1)) {
      if (!(s & 1)) ans = tre[s ^ 1] + ans;
      if (t & 1) ans = tre[t ^ 1] + ans;
    } else
      break;
    s >>= 1;
    t >>= 1;
  }
  return ans;
}
int c[200005];
inline void addt(int x, int y) {
  while (x <= n) c[x] ^= y, x += (-(x) & (x));
}
inline int sum(int x) {
  int as = 0;
  while (x) as ^= c[x], x -= (-(x) & (x));
  return as;
}
signed main() {
  n = read();
  m = read();
  int pre = 0;
  maketree(n);
  for (int i = 1; i <= n; i++) {
    k = read();
    addt(i, k);
    addt(i + 1, k);
    addtree(i, k ^ pre);
    pre = k;
  }
  for (int i = 1; i <= m; i++) {
    k = read();
    if (k == 1) {
      s = read();
      o = read();
      k = read();
      addt(s, k);
      addt(o + 1, k);
      int ll = sum(s - 1) ^ sum(s);
      int rr = sum(o + 1) ^ sum(o);
      addtree(s, ll);
      addtree(o + 1, rr);
    } else {
      s = read();
      o = read();
      it as = findtree(s + 1, o);
      as.ins(sum(s));
      printf("%d\n", 1 << as.cnt);
    }
  }
  return 0;
}
