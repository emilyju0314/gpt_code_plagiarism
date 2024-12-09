#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int flog = 0;
    int s, x;
    for (int i = 1; i <= n; i++) {
      int k = 0;
      scanf("%d", &s);
      for (int j = 1; j <= s; j++) {
        scanf("%d", &x);
        if (!a[x] && !k) {
          k = 1;
          a[x] = 1;
        }
      }
      if (k == 0) {
        flog = i;
      }
    }
    if (flog) {
      printf("IMPROVE\n");
      printf("%d ", flog);
      for (int i = 1; i <= n; i++) {
        if (!a[i]) {
          printf("%d\n", i);
          break;
        }
      }
    } else {
      printf("OPTIMAL\n");
    }
  }
  return 0;
}
