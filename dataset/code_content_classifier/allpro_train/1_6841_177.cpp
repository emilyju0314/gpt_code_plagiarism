#include <bits/stdc++.h>
using namespace std;
int iabs(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
int main() {
  int n, h, a, b, k, ta, fa, tb, fb;
  while (~scanf("%d%d%d%d%d", &n, &h, &a, &b, &k)) {
    for (int i = 0; i < k; i++) {
      scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
      if (ta == tb) {
        printf("%d\n", iabs(fa, fb));
      } else if (fa >= a && fa <= b) {
        printf("%d\n", iabs(fa, fb) + iabs(ta, tb));
      } else if (fa >= b) {
        printf("%d\n", iabs(ta, tb) + fa - b + iabs(b, fb));
      } else {
        printf("%d\n", iabs(ta, tb) + a - fa + iabs(a, fb));
      }
    }
  }
  return 0;
}
