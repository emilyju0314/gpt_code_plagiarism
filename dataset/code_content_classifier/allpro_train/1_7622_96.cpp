#include <bits/stdc++.h>
using namespace std;
long long re() {
  char c = getchar();
  long long all = 0, pd = 1;
  for (; c > '9' || c < '0'; c = getchar())
    if (c == '-') pd = -1;
  while (c >= '0' && c <= '9') all = all * 10 + c - '0', c = getchar();
  return all * pd;
}
int main() {
  long long n = re(), m = re();
  while (m--) {
    long long x = re(), y = re();
    long long ans = 0;
    long long all = n * (x - 1) + y;
    if (n & 1) {
      if (all & 1)
        ans = all / 2 + 1;
      else
        ans = all / 2 + n * n / 2 + 1;
    } else {
      if (x & 1) {
        if (y & 1)
          ans = n / 2 * (x - 1) + y / 2 + 1;
        else
          ans = n / 2 * (x - 1) + y / 2 + n * n / 2;
      } else {
        if (y & 1)
          ans = n / 2 * (x - 1) + y / 2 + n * n / 2 + 1;
        else
          ans = n / 2 * (x - 1) + y / 2;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
