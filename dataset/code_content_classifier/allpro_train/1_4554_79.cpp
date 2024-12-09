#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans[110];
  bool nums[110];
  scanf("%d", &n);
  scanf("%d", &m);
  int l1, l2;
  scanf("%d", &l1);
  m--;
  memset(ans, -1, sizeof ans);
  memset(nums, 0, sizeof nums);
  for (int i = 0; i < m; i++) {
    scanf("%d", &l2);
    int diff = l2 - l1;
    if (diff <= 0) diff += n;
    if ((ans[l1 - 1] != -1 && ans[l1 - 1] != diff) ||
        (ans[l1 - 1] != diff && nums[diff - 1]))
      return printf("-1\n"), 0;
    nums[diff - 1] = 1;
    ans[l1 - 1] = diff;
    l1 = l2;
  }
  int numi = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      while (nums[numi]) numi++;
      ans[i] = numi + 1;
      nums[numi] = 1;
    }
    printf("%d ", ans[i]);
  }
  return 0;
}
