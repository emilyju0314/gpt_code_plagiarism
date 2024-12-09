#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int a[MAXN];
bool vis[MAXN];
int gcd(int m, int n) {
  for (int r = m % n; r; m = n, n = r, r = m % n)
    ;
  return n;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, ans = 1;
    scanf("%d", &n);
    memset(vis, true, sizeof(vis));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans = max(ans, a[i]);
    for (int t = 1; t <= n; ++t) {
      int tmp = 1, pos = 0;
      for (int i = 1; i <= n; ++i)
        if (vis[i] && gcd(ans, a[i]) >= tmp) {
          tmp = gcd(ans, a[i]);
          pos = i;
        }
      vis[pos] = false;
      printf("%d ", a[pos]);
      ans = gcd(ans, a[pos]);
    }
    printf("\n");
  }
  return 0;
}
