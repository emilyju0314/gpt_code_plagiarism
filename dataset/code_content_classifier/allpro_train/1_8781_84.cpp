#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int num;
  int index;
} kep[1000000];
int ans[1000000];
bool cmp(node a, node b) { return a.num < b.num; }
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &kep[i].num);
      kep[i].index = i;
    }
    sort(kep, kep + n, cmp);
    for (int i = 0; i < n; i++) ans[kep[i].index] = i % 2;
    for (int i = 0; i < m; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
    }
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        printf("%d ", ans[i]);
      else
        printf("%d\n", ans[i]);
    }
  }
  return 0;
}
