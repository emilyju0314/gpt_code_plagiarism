#include <bits/stdc++.h>
using namespace std;
int a[100005];
int read() {
  char c = getchar();
  int f = 1, x = 0;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
int gcd(int x, int y) {
  int t = x % y;
  while (t > 0) x = y, y = t, t = x % y;
  return y;
}
int compare(int x, int y) { return x > y ? 0 : 1; }
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1, compare);
  int s = a[2] - a[1], ans = 0;
  for (int i = 3; i <= n; i++) s = gcd(s, a[i] - a[i - 1]);
  for (int i = 2; i <= n; i++) ans += (a[i] - a[i - 1]) / s - 1;
  printf("%d", ans);
  return 0;
}
