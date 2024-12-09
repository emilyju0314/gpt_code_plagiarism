#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k;
int a[maxn];
int getans(int a, int b) {
  if ((a + b) % 2 == 0) return (a + b) >> 1;
  return (a + b + 1) >> 1;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 2e9, po = 0;
    for (int i = 1; i <= n - k; i++) {
      int pos = getans(a[i], a[i + k]);
      if (pos - a[i] <= ans) ans = pos - a[i], po = pos;
    }
    printf("%d\n", po);
  }
  return 0;
}
