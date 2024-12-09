#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, ans = 0, a[105];
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    int k = i;
    while (k <= n && a[k] - a[i] <= x) k++;
    k--;
    ans = max(ans, k - i + 1);
  }
  printf("%d\n", n - ans);
}
