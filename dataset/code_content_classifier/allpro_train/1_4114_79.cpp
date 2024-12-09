#include <bits/stdc++.h>
double pointx[100010], pointy[100010];
int flag[100010], left[100010], right[100010], up[100010], down[100010], n, k;
long long ans;
int cmp_left(const void *x, const void *y) {
  return pointx[*(int *)x] > pointx[*(int *)y] ? 1 : -1;
}
int cmp_right(const void *x, const void *y) {
  return pointx[*(int *)x] < pointx[*(int *)y] ? 1 : -1;
}
int cmp_up(const void *x, const void *y) {
  return pointy[*(int *)x] > pointy[*(int *)y] ? 1 : -1;
}
int cmp_down(const void *x, const void *y) {
  return pointy[*(int *)x] < pointy[*(int *)y] ? 1 : -1;
}
void dfs(int x, int l, int r, int u, int d) {
  int ll = l, rr = r, uu = u, dd = d;
  long long height, wide;
  while (flag[left[ll + 1]]) ll++;
  while (flag[right[rr + 1]]) rr++;
  while (flag[up[uu + 1]]) uu++;
  while (flag[down[dd + 1]]) dd++;
  height = (long long)(pointx[right[rr + 1]] - pointx[left[ll + 1]] + 0.75);
  if (height < 1) height = 1;
  wide = (long long)(pointy[down[dd + 1]] - pointy[up[uu + 1]] + 0.75);
  if (wide < 1) wide = 1;
  if (x == k) {
    if (ans == 0 || height * wide < ans) {
      ans = height * wide;
      return;
    }
    return;
  }
  flag[left[ll + 1]] = 1;
  dfs(x + 1, ll + 1, rr, uu, dd);
  flag[left[ll + 1]] = 0;
  flag[right[rr + 1]] = 1;
  dfs(x + 1, ll, rr + 1, uu, dd);
  flag[right[rr + 1]] = 0;
  flag[up[uu + 1]] = 1;
  dfs(x + 1, ll, rr, uu + 1, dd);
  flag[up[uu + 1]] = 0;
  flag[down[dd + 1]] = 1;
  dfs(x + 1, ll, rr, uu, dd + 1);
  flag[down[dd + 1]] = 0;
  return;
}
int main(void) {
  int i, a, b, c, d;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    pointx[i] = a + c;
    pointx[i] /= 2;
    pointy[i] = b + d;
    pointy[i] /= 2;
    left[i] = right[i] = up[i] = down[i] = i;
  }
  memset(flag, 0, sizeof(flag));
  qsort(left + 1, n, sizeof(left[0]), cmp_left);
  qsort(right + 1, n, sizeof(left[0]), cmp_right);
  qsort(up + 1, n, sizeof(left[0]), cmp_up);
  qsort(down + 1, n, sizeof(left[0]), cmp_down);
  ans = 0;
  dfs(0, 0, 0, 0, 0);
  printf("%I64d\n", ans);
  return 0;
}
