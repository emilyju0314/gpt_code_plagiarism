#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
int main() {
  int n, k, i, j;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; ++i) {
    for (j = n - 1; j > (1 << i); --j) printf("%d ", n - (1 << i));
    for (j = min(n - 1, (1 << i)); j > (1 << (i - 1)); --j)
      printf("%d ", n - (j - (1 << (i - 1))));
    for (j = min(n - 1, (1 << (i - 1))); j >= 0; --j) printf("%d ", n);
    printf("\n");
  }
  return 0;
}
