#include <bits/stdc++.h>
using std::max;
int Calc(long long a, long long n, long long p) {
  if (a + a > p) a = p - a;
  if (a * n > p) return Calc(p % a, (a * n + p % a) / p, a);
  return max(a, p - (n - 1) * a);
}
int main() {
  int T;
  scanf("%d ", &T);
  for (int times = 0; times < T; ++times) {
    int a, n, p, h, maxdelta;
    scanf("%d %d %d %d ", &a, &n, &p, &h);
    a %= p;
    if ((long long)n * a < p)
      maxdelta = a;
    else
      maxdelta = Calc(a, n + 1, p);
    printf((h < maxdelta) ? "NO\n" : "YES\n");
  }
  return 0;
}
