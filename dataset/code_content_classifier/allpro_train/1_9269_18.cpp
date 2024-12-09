#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(int &x, int y) {
  if (x > y) x = y;
}
inline long long read() {
  char s;
  long long k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    printf("0");
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
const int maxn = 1e5 + 100;
int a[maxn];
int n, l, r, l1, r1, la, ra;
int q(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int y;
  scanf("%d", &y);
  return y;
}
void ret(int x) {
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}
int main() {
  n = read();
  if ((n / 2) % 2 == 1) {
    ret(-1);
    return 0;
  }
  memset(a, 0x3f3f3f3f, sizeof(a));
  l = 1, r = n / 2;
  la = q(l);
  ra = q(n / 2 + l);
  if (la == ra) {
    ret(l);
    return 0;
  }
  int mdl, mdr, mda, mdb;
  while (l <= r) {
    mdl = (l + r) / 2;
    mdr = mdl + n / 2;
    mda = q(mdl);
    mdb = q(mdr);
    if (mda == mdb) {
      ret(mdl);
      return 0;
    }
    if ((la < ra) ^ (mda < mdb))
      r = mdl - 1;
    else
      l = mdl + 1;
  }
  ret(-1);
  return 0;
}
