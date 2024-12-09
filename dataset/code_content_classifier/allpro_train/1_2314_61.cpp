#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const long long inf = 0x3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
int n, a, k, rt;
int siz[maxn];
bool vis[maxn];
vector<int> g[maxn];
vector<int> son[maxn];
void dfs1(int v) {
  siz[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    dfs1(g[v][i]);
    siz[v] += siz[g[v][i]];
    if (siz[g[v][i]] % 2 == 0) {
      son[v].push_back(g[v][i]);
    }
  }
}
void dfs(int v) {
  vis[v] = true;
  for (int i = 0; i < son[v].size(); i++) {
    dfs(son[v][i]);
  }
  printf("%d\n", v);
  for (int i = 0; i < g[v].size(); i++) {
    if (!vis[g[v][i]]) dfs(g[v][i]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    if (k == 0) rt = i;
    g[k].push_back(i);
  }
  if (n % 2 == 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
    dfs1(rt);
    dfs(rt);
  }
  return 0;
}
