#include <bits/stdc++.h>
using namespace std;
int solve(int m, int n) {
  int res;
  if (n >= 2 * m) return 1;
  if (n > m) return 3;
  if (n <= 1 || (n <= 3 && m > 2 * n - 1)) return -1;
  if (n == m) return 5;
  if (n <= 3) {
    if (m - n + 2 <= n) return 9;
    return 11;
  }
  m = m - n + 2;
  res = 4;
  if (m <= n / 2) return res + 1;
  while (m > n) {
    m = m - n / 2 + 1;
    res += 2;
  }
  m++;
  res += 2;
  while (m > n) {
    m = m - n + 1;
    res += 2;
  }
  res++;
  return res;
}
int main() {
  int t, m, n;
  scanf("%d%d", &m, &n);
  printf("%d\n", solve(m, n));
  return 0;
}
