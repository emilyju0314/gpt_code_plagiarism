#include <bits/stdc++.h>
using namespace std;
int n, a[200050], b[100], cnt, sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    sum ^= a[i];
    for (int j = 1; j <= cnt; j++) {
      a[i] = min(a[i], a[i] ^ b[j]);
    }
    if (a[i]) b[++cnt] = a[i];
  }
  printf("%d\n", sum ? cnt : -1);
  return 0;
}
