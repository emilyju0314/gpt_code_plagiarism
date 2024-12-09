#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (~scanf("%d", &n)) {
    bool hor[MAX];
    bool ver[MAX];
    memset(hor, false, sizeof(hor));
    memset(ver, false, sizeof(ver));
    int ans[MAX] = {0};
    int cnt = 0;
    for (int i = 0; i <= n * n - 1; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (!hor[x - 1] && !ver[y - 1]) {
        ans[cnt++] = i + 1;
        hor[x - 1] = true;
        ver[y - 1] = true;
      }
    }
    for (int i = 0; i <= cnt - 1; i++) {
      printf("%d", ans[i]);
      if (i != cnt - 1)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}
