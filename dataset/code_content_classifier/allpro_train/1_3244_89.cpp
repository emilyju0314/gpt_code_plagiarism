#include <bits/stdc++.h>
using namespace std;
int n, m, k, res, xx, yy;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  while (k--) {
    scanf("%d%d", &xx, &yy);
    int mn = xx - 1;
    mn = min(mn, n - xx);
    mn = min(mn, yy - 1);
    mn = min(mn, m - yy);
    res = max(res, (int)(mn <= 4));
  }
  if (res)
    printf("YES");
  else
    printf("NO");
  return 0;
}
