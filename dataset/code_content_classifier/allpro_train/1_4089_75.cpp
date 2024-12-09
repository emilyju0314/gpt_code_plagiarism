#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 7;
int n, nex[N];
char s[N];
int real_map[N];
vector<int> pos[N];
int fa[N], sz[N], mx[N];
int get_root(int x) { return fa[x] == x ? x : (fa[x] = get_root(fa[x])); }
void merge_node(int x, int y) {
  x = get_root(x);
  y = get_root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  mx[x] = max(mx[x], mx[y]);
  sz[x] = sz[x] + sz[y];
  fa[y] = x;
}
void solve() {
  scanf("%d%s", &n, s + 1);
  for (int i = 0; i <= n; i++) nex[i] = i + 1, real_map[i] = i;
  nex[n + 1] = n + 1;
  for (int i = 1; i <= n + 1; i++) fa[i] = i, sz[i] = i, mx[i] = i;
  for (int i = 1, p0 = 0, p1 = 0; i <= n; i++) {
    if (s[i] == '1') {
      pos[i - p0].push_back(i);
      p1 = i;
    } else if (s[i] == '0') {
      pos[i - p1].push_back(i);
      p0 = i;
    } else {
      pos[max(i - p0, i - p1)].push_back(i);
    }
  }
  printf("%d", n);
  for (int round = 2; round <= n; round++) {
    for (int i = (int)pos[round - 1].size() - 1; i >= 0; i--) {
      int id = pos[round - 1][i];
      merge_node(id, nex[id]);
    }
    int ans = 0;
    for (int i = 0; i + round - 1 <= n; i = mx[get_root(nex[i + round - 1])]) {
      if (mx[get_root(nex[i + round - 1])] <= n) ans++;
    }
    printf(" %d", ans);
  }
  puts("");
}
int main() {
  solve();
  return 0;
}
