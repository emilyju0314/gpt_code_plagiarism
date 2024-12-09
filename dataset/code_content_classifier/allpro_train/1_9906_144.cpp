#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, a[1005], x, y;
double dp[1005][1005], tmp1[1005], tmp2[1005], ans;
int main() {
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    read(a[i]);
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++)
      if (i != j) {
        dp[i][j] = (a[i] > a[j]);
      }
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    read(x);
    read(y);
    for (((j)) = (1); ((j)) <= ((n)); ((j))++)
      if (j != x && j != y) {
        tmp1[j] = dp[x][j];
        tmp2[j] = dp[j][x];
        dp[x][j] = (dp[x][j] + dp[y][j]) / 2.0;
        dp[j][x] = (dp[j][x] + dp[j][y]) / 2.0;
      }
    for (((j)) = (1); ((j)) <= ((n)); ((j))++)
      if (j != x && j != y) {
        dp[y][j] = (tmp1[j] + dp[y][j]) / 2.0;
        dp[j][y] = (tmp2[j] + dp[j][y]) / 2.0;
      }
    dp[x][y] = dp[y][x] = 0.5;
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    for ((j) = (i + 1); (j) <= (n); (j)++) {
      ans += dp[i][j];
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
