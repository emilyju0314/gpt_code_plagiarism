#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1234];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (a[i] > 2 * k) {
      k *= 2;
      ans++;
    }
    k = max(k, a[i]);
  }
  printf("%d\n", ans);
  return 0;
}
