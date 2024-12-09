#include <bits/stdc++.h>
using namespace std;
int comp(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }
int n, m, a[100010], v1, v2;
bool isBus() {
  if (a[0] != 1 || a[1] != 1) return 0;
  for (int i = 2; i < n; i++)
    if (a[i] != 2) return 0;
  return 1;
}
bool isCircle() {
  for (int i = 0; i < n; i++)
    if (a[i] != 2) return 0;
  return 1;
}
bool isStar() {
  for (int i = 0; i < n - 1; i++)
    if (a[i] != 1) return 0;
  if (a[n - 1] != n - 1) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &v1, &v2);
    a[--v1]++;
    a[--v2]++;
  }
  qsort(a, n, sizeof(int), comp);
  if (isBus())
    printf("bus topology");
  else if (isCircle())
    printf("ring topology");
  else if (isStar())
    printf("star topology");
  else
    printf("unknown topology");
  return 0;
}
