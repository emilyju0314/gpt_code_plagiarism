#include <bits/stdc++.h>
using namespace std;
int n, maxi, ans;
int a[200100], g[1001000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    g[a[i]] = a[i];
  }
  sort(a + 1, a + 1 + n);
  maxi = a[n];
  for (int i = 1; i <= maxi; i++) {
    if (g[i] != i) g[i] = g[i - 1];
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && a[i - 1] == a[i]) continue;
    for (int j = a[i] << 1; j <= maxi; j += a[i]) {
      ans = max(ans, g[j - 1] % a[i]);
    }
    ans = max(ans, maxi % a[i]);
  }
  printf("%d\n", ans);
}
