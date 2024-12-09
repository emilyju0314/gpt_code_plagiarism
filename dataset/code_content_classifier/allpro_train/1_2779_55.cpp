#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 1], b[1000000 + 1], deg[1000000 + 1], ord[1000000 + 1];
vector<int> ans;
bool cmp(int x, int y) {
  return min(deg[a[x]], deg[b[x]]) < min(deg[a[y]], deg[b[y]]);
}
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d", a + i, b + i), deg[a[i]]++, deg[b[i]]++, ord[i] = i;
  for (i = 1; i <= n; i++) deg[i] = deg[i] - (deg[i] + 1 >> 1);
  sort(ord + 1, ord + m + 1, cmp);
  for (i = 1; i <= m; i++)
    if (deg[a[ord[i]]] && deg[b[ord[i]]])
      deg[a[ord[i]]]--, deg[b[ord[i]]]--;
    else
      ans.push_back(ord[i]);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d %d\n", a[ans[i]], b[ans[i]]);
  return 0;
}
