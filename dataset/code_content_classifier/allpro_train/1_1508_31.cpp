#include <bits/stdc++.h>
using namespace std;
int a[5050], b[1000050], cnt, i, j, f[1000005], n, k;
int cmp(int i, int j) { return i < j; }
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) f[a[j] - a[i]]++;
  for (i = 1;; i++) {
    cnt = 0;
    for (j = i; j <= 1000000; j += i) cnt += f[j];
    if (cnt > k * (k + 1) / 2) continue;
    cnt = 0;
    for (j = 1; j <= n; j++) {
      if (b[a[j] % i] == i) cnt++;
      b[a[j] % i] = i;
    }
    if (cnt <= k) break;
  }
  cout << i;
  return 0;
}
