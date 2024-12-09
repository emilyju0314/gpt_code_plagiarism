#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') f = -1;
  } while (c < '0' || c > '9');
  do {
    x = x * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return f * x;
}
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
bool umin(long long &a, long long b) {
  if (b < a) return a = b, 1;
  return 0;
}
bool umax(long long &a, long long b) {
  if (b > a) return a = b, 1;
  return 0;
}
long long a[100011], suf[100011], ans[100011];
int main() {
  long long n = read(), m = read();
  for (long long i = 1; i <= m; ++i) a[i] = read();
  for (long long i = m; i; --i) suf[i] = suf[i + 1] + a[i];
  if (suf[1] < n) {
    puts("-1");
    return 0;
  }
  for (long long i = 1; i <= m; ++i) {
    if (a[i] > n - i + 1) {
      puts("-1");
      return 0;
    }
    long long pos = max(i, n - suf[i] + 1);
    ans[i] = pos;
  }
  for (long long i = 1; i <= m; ++i) printf("%lld ", ans[i]);
  return 0;
}
