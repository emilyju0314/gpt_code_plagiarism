#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[200005];
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int ans = INT_MAX;
  for (int i = 1; i <= n / 2; i++) ans = min(ans, a[i + n / 2] - a[i]);
  printf("%d", ans);
}
