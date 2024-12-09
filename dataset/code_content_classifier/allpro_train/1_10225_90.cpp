#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static const int maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}
const int MAXN = 3510;
int n, st;
int lim;
int f[51][3010];
int a[MAXN];
char s[MAXN];
int main() {
  read(n);
  read(st);
  read(lim);
  for (int i = 1; i <= n; i++) read(a[i]);
  scanf("%s", s);
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; i++) f[i][abs(st - i)] = a[i];
  for (int i = 0; i < n * n; i++) {
    for (int j = 1; j <= n; j++)
      if (f[j][i] != -1) {
        for (int k = 1; k <= n; k++)
          if ((s[k - 1] != s[j - 1]) && (a[k] > a[j]))
            f[k][i + (int)abs(k - j)] =
                max(f[k][i + (int)abs(k - j)], f[j][i] + a[k]);
      }
  }
  for (int j = 0; j <= n * n; j++)
    for (int i = 1; i <= n; i++)
      if (f[i][j] >= lim) {
        printf("%d\n", j);
        return 0;
      }
  puts("-1");
  return 0;
}
