#include <bits/stdc++.h>
using namespace std;
const int maxx = 200010;
vector<int> g[maxx];
int n;
int ans = 0, total = 0, sum = 0;
int a[maxx], b[maxx], bj[maxx];
void dfs(int x) {
  if (bj[x]) return;
  bj[x] = 1;
  dfs(a[x]);
}
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (b[i] == 1) sum++;
  }
  for (register int i = 1; i <= n; i++) {
    if (!bj[i]) {
      dfs(i);
      total++;
    }
  }
  if (sum % 2 == 0)
    sum = 1;
  else
    sum = 0;
  if (total == 1) total = 0;
  ans = total + sum;
  printf("%d", ans);
  return 0;
}
