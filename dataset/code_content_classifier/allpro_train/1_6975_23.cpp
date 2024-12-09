#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000005];
int sum = 0, tmp[1000005], sub[1000005], sz = 0, ans[5000];
void dfs(int u) {
  int i, v;
  for (i = 0; i < G[u].size(); i++) {
    v = G[u][i];
    dfs(v);
    tmp[u] = tmp[v] + tmp[u];
  }
  if (tmp[u] == sum / 3 && sz < 2 && u != G[0][0]) {
    tmp[u] = 0;
    ans[sz++] = u;
  }
}
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= (n); i++) {
    int x;
    scanf("%d%d", &x, &tmp[i]);
    G[x].push_back(i);
    sum += tmp[i];
  }
  if (sum % 3) {
    printf("-1\n");
    return 0;
  }
  dfs(G[0][0]);
  if (sz < 2)
    printf("-1\n");
  else {
    printf("%d %d\n", ans[0], ans[1]);
  }
}
