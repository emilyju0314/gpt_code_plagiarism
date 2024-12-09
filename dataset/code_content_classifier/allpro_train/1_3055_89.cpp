#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
int n, m, mod;
int fa[N], siz[N], k;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  fa[y] = x;
  siz[x] += siz[y];
  k--;
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  k = n;
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    merge(x, y);
  }
  int ans = 1;
  if (k == 1) {
    printf("%d\n", 1 % mod);
    return 0;
  }
  for (int i = 1; i <= k - 2; i++) ans = 1ll * ans * n % mod;
  for (int i = 1; i <= n; i++)
    if (find(i) == i) ans = 1ll * ans * siz[i] % mod;
  cout << ans;
  return 0;
}
