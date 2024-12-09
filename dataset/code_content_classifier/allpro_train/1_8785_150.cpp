#include <bits/stdc++.h>
using namespace std;
int T;
int n, k;
int a[100005], s1, s2, b[100005];
int vis[100005];
int main() {
  int i, flag, t1, t2, j, mn;
  cin >> T;
  int tt = T, te = 0;
  while (T--) {
    te++;
    s1 = s2 = flag = 0;
    mn = 1000000000;
    scanf("%d%d", &n, &k);
    n--;
    for (i = 1; i <= k; i++) scanf("%d", &a[i]), vis[i] = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &t1, &t2);
      if (!flag && t2) {
        flag = 1;
        s2 = s1;
        for (j = 1; j <= k; j++) b[j] = a[j];
      }
      if (t1 == 0)
        s1++;
      else
        a[t1]--;
    }
    if (!flag)
      mn = 0;
    else
      for (i = 1; i <= k; i++)
        if (a[i] == b[i]) mn = min(mn, b[i]);
    for (i = 1; i <= k; i++) {
      if (flag)
        if (a[i] == b[i])
          if (s2 >= b[i]) vis[i] = 1;
      if (s1 - mn >= a[i]) vis[i] = 2;
      if (vis[i])
        printf("Y");
      else
        printf("N");
    }
    printf("\n");
  }
  return 0;
}
