#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, b, ts, f = 1, cn = 0, n, k;
  scanf("%d", &n);
  for (i = n; i > 0; i--) {
    for (j = i; j > 0; j--) {
      k = i ^ j;
      if (k <= j && k > 0 && (k + j) > i) {
        cn++;
      }
    }
  }
  printf("%d\n", cn);
  return 0;
}
