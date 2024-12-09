#include <bits/stdc++.h>
using namespace std;
int c[1024][1024];
int main() {
  for (int i = 0, to = 1024; i < to; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1, to = i; j < to; ++j)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
  }
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (2 * k >= min(n, m))
    puts("0");
  else
    printf("%d\n",
           (int)((1LL * c[n - 1][2 * k] * c[m - 1][2 * k]) % 1000000007));
  return 0;
}
