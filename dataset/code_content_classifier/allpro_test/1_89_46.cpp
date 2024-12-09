#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline long long read() {
  long long first = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    first = first * 10 + ch - '0';
    ch = getchar();
  }
  return first * f;
}
inline void ou(long long first) {
  char ch[40];
  int len = 0;
  if (first < 0) {
    putchar('-');
    first = ~first + 1;
  }
  do {
    ch[len++] = first % 10 + '0';
    first /= 10;
  } while (first > 0);
  for (int i = len - 1; i >= 0; i--) putchar(ch[i]);
  return;
}
inline int addmod(int u_, int v_, int MOD) {
  u_ += v_;
  return u_ >= MOD ? u_ - MOD : u_;
}
inline int submod(int u_, int v_, int MOD) {
  u_ -= v_;
  return u_ < 0 ? u_ + MOD : u_;
}
const double eps = 1e-8;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
const int N = 1010;
long long a[maxn];
long long sum[maxn];
void solve() {
  int n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) {
    bool f = 0;
    for (int j = 2; j <= i + 1; ++j) {
      if (a[i] % j) {
        f = 1;
        break;
      }
    }
    if (!f) {
      puts("NO");
      return;
    }
  }
  puts("YES");
  return;
}
signed main() {
  int _ = 1;
  _ = read();
  for (int cas = 1; cas <= _; ++cas) {
    solve();
  }
  return 0;
}
