#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n, m;
int size[200010], cou[200010];
vector<int> v[200010];
void dfs(int u, int pre, int flag) {
  if (size[u] == 0) {
    cou[u] = 1;
    return;
  }
  if (flag) {
    cou[u] = 0;
  } else {
    cou[u] = 99999999;
  }
  for (int i = 0; i < size[u]; i++) {
    int x = v[u][i];
    if (x == pre) continue;
    dfs(x, u, flag ^ 1);
    if (flag) {
      cou[u] += cou[x];
    }
    if (!flag) {
      cou[u] = min(cou[u], cou[x]);
    }
  }
}
int main() {
  int x, y;
  while (~scanf("%d", &n)) {
    if (n == 1) {
      printf("1 1\n");
      continue;
    }
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
    }
    m = 0;
    for (int i = 1; i <= n; i++) {
      size[i] = v[i].size();
      if (size[i] == 0) {
        m++;
      }
    }
    dfs(1, 0, 0);
    printf("%d ", m - cou[1] + 1);
    dfs(1, 0, 1);
    printf("%d\n", cou[1]);
  }
  return 0;
}
