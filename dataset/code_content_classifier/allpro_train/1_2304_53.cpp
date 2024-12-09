#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 10;
const int maxn = 2e5 + 10;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] += a[i - 1];
  }
  int ans = a[n];
  for (int i = n - 1; i > 1; i--) ans = max(ans, a[i] - ans);
  printf("%d\n", ans);
  return 0;
}
