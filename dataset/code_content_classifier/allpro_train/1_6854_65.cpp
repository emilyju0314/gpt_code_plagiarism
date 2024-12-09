#include <bits/stdc++.h>
using namespace std;
char buffer[2000020], *p1, *p2;
template <class T>
void read(T& x) {
  char ch = ((p1 == p2 &&
              (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
                 ? EOF
                 : *p1++);
  x = 0;
  bool f = 1;
  while (!('0' <= ch && ch <= '9') && ch != '-')
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  if (ch == '-')
    f = 0,
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  while ('0' <= ch && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0',
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  x = (f) ? x : -x;
}
int _num[20];
template <class T>
void write(T x, char sep = '\n') {
  if (!x) {
    putchar('0'), putchar(sep);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int c = 0;
  while (x) _num[++c] = x % 10, x /= 10;
  while (c) putchar('0' + _num[c--]);
  putchar(sep);
}
int reads(char* s) {
  int l = 0;
  char ch = ((p1 == p2 &&
              (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
                 ? EOF
                 : *p1++);
  while (!('a' <= ch && ch <= 'z'))
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  while (('a' <= ch && ch <= 'z'))
    s[l++] = ch,
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  s[l] = '\0';
  return l;
}
char s[120];
int n;
int dp[120][120];
int dp2[120][120];
int main() {
  read(n), reads(s + 1);
  for (register int i = 1; i <= n; i++) dp[i][i] |= (1 << (s[i] - 'a'));
  for (register int l = 2; l <= n; l++) {
    for (register int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      for (register int k = i; k < j; k++) {
        for (register int a = 0; a < 25; a++) {
          if ((dp[i][k] & (1 << a)) && (dp[k + 1][j] & (1 << (a + 1)))) {
            dp[i][j] |= (1 << a);
          }
          if ((dp[i][k] & (1 << (a + 1))) && (dp[k + 1][j] & (1 << a))) {
            dp[i][j] |= (1 << a);
          }
        }
      }
    }
  }
  for (register int l = 1; l <= n; l++) {
    for (register int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      int& ans = dp2[i][j];
      if (dp[i][j]) {
        ans = 1;
        continue;
      }
      ans = n + 1;
      for (register int k = i; k < j; k++)
        ans = min(ans, dp2[i][k] + dp2[k + 1][j]);
    }
  }
  printf("%d\n", n - dp2[1][n]);
  return 0;
}
