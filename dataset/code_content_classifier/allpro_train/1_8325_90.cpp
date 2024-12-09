#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, fm, sm, x;
  scanf("%d", &t);
  for (int w = 0; w < t; w++) {
    scanf("%d", &n);
    fm = sm = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (x >= fm) {
        sm = fm;
        fm = x;
      } else if (x >= sm)
        sm = x;
    }
    printf("%d\n", min(sm - 1, n - 2));
  }
  return 0;
}
