#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, m, n, x, y, inp, flag, first, last, ct, a1;
int a[2000], b[2000];
int main() {
  scanf("%d%d%d", &n, &l, &m);
  for (i = 1; i <= n; i++) {
    memset(b, 0, sizeof(b));
    printf("? ");
    k = 0;
    x = 1 << i;
    for (j = 1; j <= n; j++) {
      if ((j - 1) % x < (x / 2)) {
        b[j] = 1;
        k++;
      }
    }
    printf("%d", k);
    for (j = 1; j <= n; j++)
      if (b[j]) printf(" %d", j);
    printf("\n");
    fflush(stdout);
    if (k % 2 == 0)
      flag = l ^ m;
    else
      flag = m;
    scanf("%d", &inp);
    if (inp == flag) break;
  }
  for (j = 1; j <= n; j++)
    if (b[j]) a[++ct] = j;
  y = i;
  first = 1;
  last = ct;
  while (first < last) {
    printf("? %d", (last - first + 1) / 2);
    k = (last - first + 1) / 2;
    for (i = first; i < first + k; i++) printf(" %d", a[i]);
    printf("\n");
    fflush(stdout);
    if (k % 2 == 0)
      flag = l ^ m;
    else
      flag = m;
    scanf("%d", &inp);
    if (inp == flag)
      last -= k;
    else
      first += k;
  }
  a1 = a[first];
  ct = 0;
  memset(a, 0, sizeof(a));
  for (i = a1 - x / 2; i >= 1; i -= x) a[++ct] = i;
  for (i = a1 + x / 2; i <= n; i += x) a[++ct] = i;
  first = 1;
  last = ct;
  while (first < last) {
    printf("? %d", (last - first + 1) / 2);
    k = (last - first + 1) / 2;
    for (i = first; i < first + k; i++) printf(" %d", a[i]);
    printf("\n");
    fflush(stdout);
    if (k % 2 == 0)
      flag = l ^ m;
    else
      flag = m;
    scanf("%d", &inp);
    if (inp == flag)
      last -= k;
    else
      first += k;
    if (inp == flag && last - first % 2 == 0) last--;
  }
  printf("! %d %d\n", min(a1, a[first]), max(a1, a[first]));
  return 0;
}
