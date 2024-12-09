#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n, m, a[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = m; i <= 100; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) cnt += a[j] / i;
    ans = max(ans, i * cnt);
  }
  printf("%d\n", ans);
  return 0;
}
