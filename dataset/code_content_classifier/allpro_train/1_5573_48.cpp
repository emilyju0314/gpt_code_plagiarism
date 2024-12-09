#include <bits/stdc++.h>
using namespace std;
int q[107];
int invq[107];
int s[107];
int res[213][107];
bool ismatching(int a[], int b[], int n) {
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) return false;
  return true;
}
int main() {
  int i, j, k, l, m, n, x, y, z, a, b, r;
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 1; i <= n; i++) scanf("%d", &q[i]);
  for (i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (i = 1; i <= n; i++) invq[q[i]] = i;
  for (i = 1; i <= n; i++) res[0 + 103][i] = i;
  for (j = 1; j <= k; j++)
    for (i = 1; i <= n; i++) res[j + 103][i] = res[j - 1 + 103][q[i]];
  for (j = -1; j >= -k; j--)
    for (i = 1; i <= n; i++) res[j + 103][i] = res[j + 1 + 103][invq[i]];
  bool flag = false;
  for (j = -k; j <= k; j++)
    if (ismatching(res[j + 103], s, n)) flag = true;
  if (!flag || ismatching(res[0 + 103], s, n)) {
    printf("NO\n");
    return 0;
  }
  if (ismatching(q, invq, n)) {
    if (k == 1)
      printf("YES\n");
    else
      printf("NO\n");
    return 0;
  }
  for (j = 1; j <= k; j++)
    if (ismatching(res[j + 103], s, n)) break;
  if ((k - j) % 2 == 0) {
    printf("YES\n");
    return 0;
  }
  for (j = -1; j >= -k; j--)
    if (ismatching(res[j + 103], s, n)) break;
  if ((k + j) % 2 == 0) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
