#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int l[2][500005];
int main() {
  int n, z;
  scanf("%d%d", &n, &z);
  for (int i = 0; i < n; i++) {
    int c = i % 2;
    scanf("%d", &l[c][0]);
    for (int j = 1; j <= l[c][0]; j++) scanf("%d", &l[c][j]);
    if (!i) continue;
    int q = 1, p = 1;
    while (q <= l[c][0] && p <= l[c ^ 1][0] && l[c][q] == l[c ^ 1][p]) q++, p++;
    if (q > l[c][0] && p <= l[c ^ 1][0])
      return 0 * puts("-1");
    else if (q > l[c][0] && p > l[c ^ 1][0])
      a[0]++, a[z]--;
    else if (q <= l[c][0] && p > l[c ^ 1][0])
      a[0]++, a[z]--;
    else if (q <= l[c][0] && p <= l[c ^ 1][0]) {
      int t1 = l[c ^ 1][p], t2 = l[c][q];
      if (t1 < t2) {
        a[0]++, a[z - t2 + 1]--, a[z - t1 + 1]++, a[z]--;
      } else if (t2 < t1) {
        a[z - t1 + 1]++, a[z - t2 + 1]--;
      }
    }
  }
  int k = 0;
  for (int i = 0; i < z; i++) {
    k += a[i];
    if (k >= n - 1) return 0 * printf("%d\n", i);
  }
  puts("-1");
  return 0;
}
