#include <bits/stdc++.h>
using namespace std;
bool tab[50005];
int main() {
  int n, m, k, x;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    memset(tab, 0, sizeof(tab));
    scanf("%d", &k);
    bool flag = 0;
    while (k--) {
      scanf("%d", &x);
      if (tab[20000 - x]) flag = 1;
      tab[20000 + x] = 1;
    }
    if (!flag) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
