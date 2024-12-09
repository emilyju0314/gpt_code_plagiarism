#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 750 + 5;
const long long INF = 1e18 + 5;
inline long long read() {
  long long sum = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * fh;
}
inline int read2() {
  char c = getchar();
  while (c != 'a' && c != 'b' && c != 'c' && c != '?') c = getchar();
  return c == '?' ? 0 : c - 'a' + 1;
}
inline int read3() {
  char c = getchar();
  while (c < 'a' || c > 'z') {
    c = getchar();
  }
  return c - 'a';
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
inline long long ab(long long x) { return x < 0 ? -x : x; }
inline long long fpow(long long qwe, long long asd, long long zxc) {
  if (asd < 0) return 0;
  long long a = qwe, b = 1, c = asd;
  while (c) {
    if (c & 1) b = b * a % zxc;
    a = a * a % zxc;
    c >>= 1;
  }
  return b;
}
int pi[N] = {0}, pil[N], cou = 0;
int ans[N] = {0};
inline void csh() {
  int n = 1e6;
  for (int i = 2; i <= n; ++i) {
    if (!pi[i]) pil[++cou] = i;
    for (int j = 1; j <= cou; ++j) {
      if (i * pil[j] > n) break;
      pi[i * pil[j]] = 1;
      if (i % pil[j] == 0) break;
    }
  }
  int sz = 1;
  ans[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!pi[i]) ans[i] += 1;
    int x = sqrt(i);
    if (x != sz && !pi[x]) {
      sz = x;
      ans[i] -= 1;
    }
    ans[i] += ans[i - 1];
  }
}
int main() {
  int t = read();
  csh();
  while (t) {
    --t;
    int n = read();
    write(ans[n]), putchar('\n');
  }
}
