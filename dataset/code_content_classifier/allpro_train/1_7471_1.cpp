#include <bits/stdc++.h>
using namespace std;
int fa[100010];
long long dep[100010];
int find(int x) {
  if (x != fa[x]) {
    int rt = find(fa[x]);
    dep[x] = (dep[x] + dep[fa[x]] + 1000000007) % 1000000007;
    fa[x] = rt;
  }
  return fa[x];
}
int main() {
  int n;
  cin >> n;
  int i, j;
  for (i = 1; i <= n; i++) {
    fa[i] = i;
    dep[i] = 0;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int v, x;
      cin >> v >> x;
      int rt = find(v);
      int now = (dep[v] + x + 1000000007) % 1000000007;
      ans = (ans + now + 1000000007) % 1000000007;
      fa[rt] = i;
      dep[rt] = now;
    }
  }
  cout << ans << endl;
  return 0;
}
