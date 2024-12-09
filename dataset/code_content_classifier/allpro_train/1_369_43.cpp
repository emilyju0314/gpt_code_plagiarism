#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, b, a0 = 0, b0 = 0, a1 = 0, b1 = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    if (a == 0)
      a0++;
    else if (a == 1)
      a1++;
    if (b == 0)
      b0++;
    else if (b == 1)
      b1++;
  }
  printf("%d\n", min(a0, a1) + min(b0, b1));
  return 0;
}
