#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 5;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l, r;
  int ans = 0;
  for (l = 1; l < n;) {
    for (r = l + 1; r <= n; r++) {
      if (a[r] == a[r - 1]) {
        r--;
        break;
      }
    }
    if (r == n + 1) r--;
    if (r - l > 1) {
      if ((r - l + 1) % 2 == 0) {
        ans = max(ans, (r - l + 1) / 2 - 1);
        for (int i = l + 1; i < r; i++) {
          if (i <= (r + l) / 2)
            a[i] = a[l];
          else
            a[i] = a[r];
        }
      } else {
        ans = max(ans, (r - l) / 2);
        for (int i = l + 1; i < r; i++) a[i] = a[l];
      }
      l = r;
    } else
      l++;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
