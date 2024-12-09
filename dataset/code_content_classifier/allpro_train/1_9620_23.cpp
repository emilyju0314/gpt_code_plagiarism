#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <class T>
inline void umin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
inline void umax(T &x, T y) {
  x = x > y ? x : y;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const long long lim = 10004205361450474LL;
long long f[10005][6], p[10005];
int n = 9999;
int main() {
  for (register int i = (0); i <= (n); i++) f[i][1] = i + 1;
  for (register int i = (1); i <= (5); i++) {
    for (register int x = (0); x <= (n); x++) {
      p[0] = x;
      for (register int j = (1); j <= (x + 2); j++) {
        p[j] = p[j - 1] + 1 + f[min(1LL * n, p[j - 1])][i - 1];
        if (p[j] > n) {
          p[x + 2] = p[j] + (1LL + f[n][i - 1]) * (x + 2 - j);
          break;
        }
      }
      f[x][i] = p[x + 2] - x - 1;
    }
  }
  long long l = 1, r = lim;
  int i = 5;
  while (i) {
    int x = min(1LL * n, l - 1);
    p[0] = l - 1;
    for (register int j = (1); j <= (x + 2); j++)
      p[j] = p[j - 1] + 1 + f[min(1LL * n, p[j - 1])][i - 1];
    printf("%d ", x + 1);
    for (register int j = (1); j <= (x + 1); j++) printf("%lld ", p[j]);
    puts("");
    fflush(stdout);
    int c;
    read(c);
    if (c == -1) {
      return 0;
    }
    l = p[c] + 1;
    r = p[c + 1] - 1;
    i--;
  }
  return 0;
}
