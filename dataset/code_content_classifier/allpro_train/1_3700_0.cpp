#include <bits/stdc++.h>
long long n, p;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
long long check(long long len) {
  long long zyc;
  if (len <= p)
    zyc = (1 + len) * (((len - 1) > 0 ? (len - 1) : (0 - (len - 1))) + 1) / 2;
  else {
    zyc = (1 + p - 1) *
          (((p - 1 - 1) > 0 ? (p - 1 - 1) : (0 - (p - 1 - 1))) + 1) / 2;
    len -= p;
    if (len & 1)
      zyc = zyc +
            (p + p + len / 2) *
                (((p + len / 2 - p) > 0 ? (p + len / 2 - p)
                                        : (0 - (p + len / 2 - p))) +
                 1) /
                2 +
            (p + len / 2 + p) *
                (((p - p + len / 2) > 0 ? (p - p + len / 2)
                                        : (0 - (p - p + len / 2))) +
                 1) /
                2;
    else
      zyc = zyc +
            (p + p + len / 2) *
                (((p + len / 2 - p) > 0 ? (p + len / 2 - p)
                                        : (0 - (p + len / 2 - p))) +
                 1) /
                2 +
            (p + len / 2 - 1 + p) *
                (((p - p + len / 2 - 1) > 0 ? (p - p + len / 2 - 1)
                                            : (0 - (p - p + len / 2 - 1))) +
                 1) /
                2;
  }
  return zyc >= n;
}
long long binsch(long long fr, long long to) {
  long long l = fr - 1, r = to + 1, m;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (check(m) != 1)
      l = m;
    else
      r = m;
  }
  return r;
}
int main() {
  n = read();
  p = read();
  long long r = 2 * sqrt(n) + 1;
  long long ans = binsch(1, r);
  printf("%I64d", ans);
}
