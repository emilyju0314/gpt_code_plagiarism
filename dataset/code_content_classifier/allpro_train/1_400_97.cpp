#include <bits/stdc++.h>
using namespace std;
int fa[51], d[51];
int root(int a) {
  if (a == fa[a]) return a;
  return fa[a] = root(fa[a]);
}
int main() {
  int n, m, i, j, a, b;
  scanf("%d%d", &n, &m);
  if (m > n) {
    printf("NO\n");
    return 0;
  }
  if (n == 1) {
    printf("YES\n");
    if (m == 1)
      printf("0\n");
    else
      printf("1\n1 1\n");
    return 0;
  }
  for (i = 1; i <= n; i++) fa[i] = i, d[i] = 0;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    d[a]++, d[b]++;
    if (a == b || d[a] > 2 || d[b] > 2) {
      printf("NO\n");
      return 0;
    }
    int ra = root(a), rb = root(b);
    if (ra != rb)
      fa[ra] = rb;
    else if (i < n - 1) {
      printf("NO\n");
      return 0;
    }
  }
  puts("YES");
  printf("%d\n", n - m);
  for (i = 1; i <= n; i++)
    while (d[i] < 2) {
      int ra = root(i);
      for (j = i + 1; j <= n; j++)
        if (d[j] < 2) {
          int rb = root(j);
          if (ra != rb || m + 1 == n) {
            m++;
            d[i]++, d[j]++;
            fa[ra] = rb;
            printf("%d %d\n", i, j);
            break;
          }
        }
    }
  return 0;
}
