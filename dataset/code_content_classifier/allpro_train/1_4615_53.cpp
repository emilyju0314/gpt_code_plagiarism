#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxm = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, k, m;
int par[maxn];
int s[maxn];
void init() {
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    s[i] = 1;
  }
}
int find(int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
void unite(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  par[fx] = fy;
  s[fy] += s[fx];
  s[fx] = 0;
}
bool cmp(const int &a, const int &b) { return a > b; }
int main() {
  scanf("%d%d", &n, &k);
  init();
  while (k--) {
    int u, v;
    scanf("%d%d", &u, &v);
    unite(u, v);
  }
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (find(u) == find(v)) {
      s[par[u]] = 0;
    }
  }
  sort(s + 1, s + n + 1, cmp);
  printf("%d\n", s[1]);
  return 0;
}
