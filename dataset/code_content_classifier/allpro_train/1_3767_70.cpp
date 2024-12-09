#include <bits/stdc++.h>
using namespace std;
int a[3000];
int main() {
  int i, n, total;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  total = 0;
  for (i = 1; i < n; i++) {
    if (a[i - 1] >= a[i]) {
      total += abs(a[i] - a[i - 1]) + 1;
      a[i] = a[i - 1] + 1;
    }
  }
  printf("%d\n", total);
  return 0;
}
