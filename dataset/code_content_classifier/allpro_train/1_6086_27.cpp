#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
int x[100000], y[100000], ans1[100000], ans2[100000], L[100000], pos[100000];
pair<int, int> val[100000];
int solve(int x[], int n, int r, int s, int ans[]) {
  int tot = 0;
  if (r <= n - 1 - s) {
    for (int i = n - r; i < n; i++) ans[tot++] = i;
    for (int i = n - r - 1; i > s; i--) ans[tot++] = i;
    for (int i = s - 1; i >= 0; i--) ans[tot++] = i;
    return (x[n - 1] - x[0]) + (x[n - 1] - x[s]);
  }
  for (int i = s + 1; i < n; i++) ans[tot++] = i;
  r -= n - 1 - s;
  for (int i = 0; i < s - 1; i++) val[i] = make_pair(x[i + 1] - x[i], i);
  sort(val, val + s - 1);
  for (int i = 0; i < s - 1; i++) pos[val[i].second] = i;
  int sum = 0;
  for (int i = 0; i < r; i++) sum += val[i].first;
  int minv = 2 * sum, loc1 = 0, loc2 = r - 1;
  for (int i = 0, j = r - 1; i < r; i++) {
    if (pos[i] <= j) {
      sum -= val[pos[i]].first;
    } else {
      sum -= val[j].first;
      j--;
    }
    while (val[j].second <= i) j--;
    if (x[i + 1] - x[0] + sum * 2 < minv) {
      minv = x[i + 1] - x[0] + sum * 2;
      loc1 = i + 1;
      loc2 = j;
    }
  }
  int cnt = 0;
  for (int i = 0; i <= loc2; i++)
    if (val[i].second >= loc1) L[cnt++] = val[i].second;
  sort(L, L + cnt);
  int last = s - 1;
  for (int i = cnt - 1, j; i >= 0; i = j) {
    for (j = i - 1; j >= 0 && L[j] + 1 == L[j + 1]; j--)
      ;
    for (int k = last; k > L[i] + 1; k--) ans[tot++] = k;
    for (int k = j + 1; k <= i; k++) ans[tot++] = L[k];
    ans[tot++] = L[i] + 1;
    last = L[j + 1] - 1;
  }
  for (int i = last; i >= (loc1 + 1); i--) ans[tot++] = i;
  for (int i = 0; i < loc1 + 1; i++) ans[tot++] = i;
  return minv + (x[n - 1] - x[0]) + (x[n - 1] - x[s]);
}
int main() {
  int n, l, s;
  scanf("%d%d%d", &n, &l, &s);
  s--;
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < n; i++) y[i] = -x[n - 1 - i];
  if (s != n - 1 && l == n - 1 || s != 0 && l == 0) {
    printf("-1\n");
    return 0;
  }
  int sum1 = solve(x, n, n - 1 - l, s, ans1);
  int sum2 = solve(y, n, l, n - 1 - s, ans2);
  if (sum1 < sum2) {
    printf("%d\n", sum1);
    for (int i = 0; i < n - 1; i++)
      if (i < n - 2)
        printf("%d ", ans1[i] + 1);
      else
        printf("%d\n", ans1[i] + 1);
  } else {
    printf("%d\n", sum2);
    for (int i = 0; i < n - 1; i++) ans2[i] = n - 1 - ans2[i];
    for (int i = 0; i < n - 1; i++)
      if (i < n - 2)
        printf("%d ", ans2[i] + 1);
      else
        printf("%d\n", ans2[i] + 1);
  }
  return 0;
}
