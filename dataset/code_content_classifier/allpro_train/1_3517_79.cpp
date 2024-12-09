#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];
int n, i;
int c[1000005];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (a[i] != b[i]) cnt++;
  }
  if (cnt == 1) {
    int p = 0;
    for (i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        p = i;
      }
    }
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; i++)
      if (i != p) c[a[i]]++;
    for (i = 1; i <= n; i++)
      if (c[i] == 0) a[p] = i;
    for (i = 1; i <= n; i++) printf("%d ", a[i]);
  } else {
    int p1 = 0, p2 = 0;
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    int np1 = 0, np2 = 0;
    for (i = 1; i <= n; i++)
      if (a[i] != b[i]) {
        if (!p1)
          p1 = i, a1 = a[i], b1 = b[i];
        else
          p2 = i, a2 = a[i], b2 = b[i];
      }
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; i++)
      if (i != p1 && i != p2) c[a[i]]++;
    for (i = 1; i <= n; i++)
      if (c[i] == 0) {
        if (!np1)
          np1 = i;
        else
          np2 = i;
      }
    if ((np1 == a1 && np2 == b2) || (np1 == b1 && np2 == a2))
      a[p1] = np1, a[p2] = np2;
    else
      a[p2] = np1, a[p1] = np2;
    for (i = 1; i <= n; i++) printf("%d ", a[i]);
  }
  return 0;
}
