#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[55];
bool vis[55];
long long ans;
void init() {
  for (int i = 0; i < n; i++) {
    fa[i] = i;
  }
}
int findfa(int x) {
  while (fa[x] != x) {
    x = fa[x];
  }
  return x;
}
int findfather(int x) {
  if (fa[x] != x) {
    int root = findfather(fa[x]);
    return fa[x] = root;
  } else {
    return x;
  }
}
void union_nodes(int a, int b) {
  int a1 = findfather(a);
  int b1 = findfather(b);
  if (a1 != b1) {
    fa[a1] = b1;
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  ans = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    union_nodes(x, y);
  }
  for (int i = 1; i <= n; i++) {
    int x = findfather(i);
    if (!vis[x]) {
      vis[x] = 1;
    } else {
      ans *= 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
