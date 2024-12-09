#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    bool f = false;
    int l, r;
    for (int i = 1; i <= n - 1; i++) {
      if (abs(a[i + 1] - a[i]) >= 2) {
        l = i;
        r = i + 1;
        f = true;
        break;
      }
    }
    if (f) {
      printf("YES\n");
      printf("%d %d\n", l, r);
    } else
      printf("NO\n");
  }
}
