#include <bits/stdc++.h>
using namespace std;
long long flag[5000003];
int main() {
  memset(flag, 0, sizeof(flag));
  int n, m;
  scanf("%d %d", &n, &m);
  int i;
  for (i = 1; i <= 5000000; i++) {
    int j;
    for (j = 1; i * j <= m && i + j <= 2 * n; j++) {
      if ((i + j) % 2 == 0) {
        if (i == j)
          flag[j] += 2;
        else
          flag[j]++;
      }
    }
  }
  long long sum = 0;
  for (i = 1; i <= n; i++) {
    sum += 2 * min(((long long)i) * i, (long long)m);
  }
  for (i = 1; i <= 5000000; i++) {
    if (flag[i] >= 2) sum -= flag[i] - 1;
  }
  printf("%I64d\n", sum);
  return 0;
}
