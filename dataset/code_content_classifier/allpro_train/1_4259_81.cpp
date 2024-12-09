#include <bits/stdc++.h>
using namespace std;
char rbuf[1 << 15];
char *p1 = rbuf, *p2 = rbuf;
int getint() {
  char ch;
  while ((ch = ({
            if (p1 == p2) {
              p2 = rbuf + fread(rbuf, 1, 1 << 15, stdin);
              p1 = rbuf;
            }
            p1 == p2 ? EOF : *(p1++);
          })) < '!')
    ;
  int x = ch ^ '0';
  while ((ch = ({
            if (p1 == p2) {
              p2 = rbuf + fread(rbuf, 1, 1 << 15, stdin);
              p1 = rbuf;
            }
            p1 == p2 ? EOF : *(p1++);
          })) > '!')
    x = (x * 10) + (ch ^ '0');
  return x;
}
int invi[105];
int main() {
  invi[1] = 100;
  for (int i = 2; i <= 100; ++i) {
    invi[i] =
        1LL * (998244353 - 998244353 / i) * invi[998244353 % i] % 998244353;
  }
  const int n = getint();
  register int fi = 0;
  for (int i = 1; i <= n; ++i) {
    fi = 1LL * (fi + 1) * invi[getint()] % 998244353;
  }
  printf("%d\n", fi);
}
