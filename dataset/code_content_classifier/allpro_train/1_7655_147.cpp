#include <bits/stdc++.h>
const int maxn = 100010;
using namespace std;
long long a[maxn][10];
long long b[maxn][10];
long long c[maxn] = {0};
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (i = 1; i <= 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%I64d", &a[i][j]);
      if (j == 1) b[i][1] = min(a[i][0], a[i][1]);
      if (j == 3) b[i][2] = min(a[i][2], a[i][3]);
      if (b[i][1] != 0 && b[i][2] != 0) c[i] = b[i][1] + b[i][2];
    }
  }
  for (i = 1; i <= 4; i++) {
    if (c[i] <= n) {
      printf("%d %I64d %I64d\n", i, b[i][1], n - b[i][1]);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
