#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MAXR = 1000005;
long long cubic_root(long long x) {
  long long l = 0, r = MAXR;
  while (l != r) {
    long long m = (l + r + 1) / 2;
    if (m * m * m > x)
      r = m - 1;
    else
      l = m;
  }
  return l;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; q++) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    long long res = a * b;
    long long k1 = cubic_root(res);
    if (k1 * k1 * k1 != res) {
      printf("No\n");
    } else if (a % k1 == 0 && b % k1 == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
