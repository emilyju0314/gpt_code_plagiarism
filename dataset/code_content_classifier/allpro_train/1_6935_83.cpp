#include <bits/stdc++.h>
using namespace std;
char a[2000005], b[1000005];
class Frac {
 public:
  int p, q;
  Frac(int _p = 0, int _q = 0) {
    p = _p;
    q = _q;
  }
  Frac operator+(const Frac &u) { return Frac(p + u.p, q + u.q); }
  bool operator<(const Frac &u) const { return p * 1LL * u.q < q * 1LL * u.p; }
  void print() { printf("(%d/%d)\n", p, q); }
};
Frac w[1000005];
int nw;
int flag = 0;
void handle() {
  int i, j = 1;
  for (i = 1; b[i]; i++) {
    if ((b[i] == 'L' || b[i] == 'R') && b[i] == b[i - 1]) {
      a[j++] = 'X';
    }
    a[j++] = b[i];
  }
  if (b[i - 1] == b[1]) flag = 1;
  nw = 0;
  j = 0;
  Frac d(0, 0);
  for (i = 1; a[i]; i++) {
    if (a[i] == 'L' || a[i] == 'R') {
      if ((a[i] == 'L') ^ (i % 2) ^ j) {
        w[nw++] = d;
        d.p = 0;
        d.q = 0;
        j = 1 - j;
      }
      d.p++;
    }
    d.q++;
  }
  w[nw++] = d;
}
template <class T>
T max(T aa, T bb, T cc) {
  return max(aa, max(bb, cc));
}
int go(int firststep) {
  Frac d(0, 0);
  int two = 0, i, shift = 0, firstmark = 0;
  for (i = 0; i < nw; i++) {
    if ((shift % 2) != (i % 2)) {
      if (w[i].p >= 2 || firststep && w[i].p >= 1) {
        if (d.q == 0) {
          firstmark = 1;
        }
        d.q++, shift = 1 - shift;
        firststep = 0;
      } else if (w[i].p == 1)
        two++;
    }
    if ((shift % 2) == (i % 2)) {
      d.p += w[i].p;
    }
    d.q += w[i].q;
  }
  if (flag && !firstmark) {
    ++d.q;
  }
  if (d.q % 2) {
    if (shift % 2 != (nw - 1) % 2 && w[nw - 1].p == 1) {
      --two;
      ++d.p;
      ++d.q;
    } else
      ++d.q;
  }
  if (d.q > d.p * 2) {
    d.p += two;
    d.q += two * 2;
  }
  return d.p * 100000000LL / d.q;
}
int go2(void) {
  int i;
  Frac d(0, 0);
  for (i = 1; a[i]; i++) {
    if (a[i] == 'L' || a[i] == 'R') d.p++;
    d.q++;
  }
  if (d.q % 2 == 0) ++d.q;
  d.q *= 2;
  return d.p * 100000000LL / d.q;
}
int main(void) {
  scanf("%s", b + 1);
  handle();
  int ans = max(go(0), go(1), go2());
  printf("%d.%06d\n", ans / 1000000, ans % 1000000);
  return 0;
}
