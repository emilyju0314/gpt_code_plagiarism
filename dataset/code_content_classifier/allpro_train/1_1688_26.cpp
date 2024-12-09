#include <bits/stdc++.h>
using namespace std;
int n, m, a[1050];
bool vis[2][1050][1050];
void dfs(bool took, int sum, int idx) {
  if (!sum && took) exit(puts("YES"));
  if (idx == n || vis[took][sum][idx]) return;
  vis[took][sum][idx] = 1;
  dfs(1, (sum + a[idx]) % m, idx + 1);
  dfs(0, sum, idx + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  if (n > m) return puts("YES");
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  dfs(0, 0, 0);
  puts("NO");
  return 0;
}
