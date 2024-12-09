#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, t;
int a[100010];
bool b[100010];
vector<int> v[100010];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(b, 0, sizeof b);
  k = 0;
  for (i = 1; i <= n; i++) {
    if (b[i]) continue;
    t = i;
    b[t] = true;
    v[++k].push_back(t);
    while (!b[a[t]]) {
      t = a[t];
      b[t] = true;
      v[k].push_back(t);
    }
  }
  for (i = 1; i <= k; i++) {
    if (v[i].size() == 1) {
      printf("YES\n");
      for (j = 1; j <= n; j++)
        if (j != v[i][0]) printf("%d %d\n", v[i][0], j);
      return 0;
    }
  }
  for (i = 1; i <= k; i++) {
    if (v[i].size() == 2) {
      for (j = 1; j <= n; j++)
        if (v[j].size() & 1) {
          printf("NO\n");
          return 0;
        }
      printf("YES\n");
      printf("%d %d\n", v[i][0], v[i][1]);
      for (j = 1; j <= k; j++)
        if (j != i) {
          for (t = 0; t < v[j].size(); t++)
            printf("%d %d\n", v[i][t & 1], v[j][t]);
        }
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
