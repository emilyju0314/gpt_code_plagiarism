#include <bits/stdc++.h>
using namespace std;
int m, flag, odd, even, a[1005], tot;
pair<int, int> ans[1005 * 1005];
int main() {
  scanf("%d", &m);
  for (int i = (1); i <= (m); i++) scanf("%d", &a[i]);
  for (int l = 1, r = m, L = 1, R = a[m] + 1; l <= r; l++, r--) {
    for (int i = (1); i <= (a[l] - a[l - 1]); i++) {
      for (int j = (L + 1); j <= (R); j++) ans[++tot] = pair<int, int>(j, L);
      L++;
    }
    R = a[r - 1] + 1;
  }
  printf("%d\n", tot);
  for (int i = (1); i <= (tot); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
