#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 22);
int n, m, ans;
bool a[N], vis[N];
void dfs(int now) {
  if (vis[now]) {
    return;
  }
  vis[now] = true;
  for (int i = 0; i < n; ++i) {
    if (now & (1 << i)) {
      dfs(now ^ (1 << i));
    }
  }
  if (a[now]) {
    dfs(now ^ ((1 << n) - 1));
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int temp;
    scanf("%d", &temp);
    a[temp] = true;
  }
  for (int i = 0; i < N; ++i) {
    if (!a[i] || vis[i]) {
      continue;
    }
    ++ans;
    dfs(((1 << n) - 1) ^ i);
  }
  printf("%d\n", ans);
  return 0;
}
