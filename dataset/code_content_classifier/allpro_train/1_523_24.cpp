#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, group = 1, sub = 0, ans = 0;
  scanf("%I64d %I64d %I64d", &n, &m, &k);
  long long a[m];
  for (int i = 0; i < m; i++) {
    scanf("%I64d", a + i);
    --a[i];
  }
  for (long long i = 1, div = a[0] / k; i < m; i++) {
    if ((a[i] - sub) / k == div) {
      ++group;
    } else {
      ++ans;
      sub += group;
      div = (a[i] - sub) / k;
      group = 1;
    }
  }
  printf("%I64d\n", ans + 1);
  return 0;
}
