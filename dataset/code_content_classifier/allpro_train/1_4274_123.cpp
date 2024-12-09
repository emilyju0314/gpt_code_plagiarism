#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int indeg[maxn], fa[maxn], co[maxn], dfn[maxn], low[maxn], cs[maxn], rc[maxn],
    num, tco;
int sta[maxn], ins[maxn], stop;
int wzj[maxn];
vector<int> sagitta[maxn];
int n;
void dfs(int x) {
  dfn[x] = low[x] = ++num;
  sta[++stop] = x;
  ins[x] = true;
  int v = fa[x];
  if (!ins[v]) {
    dfs(v);
    low[x] = min(low[x], low[v]);
  } else {
    if (ins[v] == 1) low[x] = min(low[x], dfn[v]);
  }
  if (low[x] == dfn[x]) {
    while (sta[stop] != x) {
      co[sta[stop]] = tco;
      ins[sta[stop]] = 2;
      cs[tco]++;
      stop--;
    }
    if (cs[tco]) {
      cs[tco]++;
      co[sta[stop]] = tco++;
    }
    ins[sta[stop]] = 2;
    stop--;
  }
}
int dfs2(int x) { return rc[x] = (rc[x] ? rc[x] : dfs2(fa[x])); }
int main() {
  tco = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> fa[i];
    indeg[fa[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= n; i++) rc[i] = co[i];
  for (int i = 1; i <= n; i++) dfs2(i);
  int leaf = 0;
  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0) {
      sagitta[rc[i]].push_back(i);
      leaf += (sagitta[rc[i]].size() != 1);
    }
  for (int i = 1; i <= n; i++)
    if (co[i]) wzj[co[i]] = i;
  tco--;
  if (tco == 1 && cs[1] == n) {
    puts("0");
    return 0;
  }
  printf("%d\n", tco + leaf);
  if (tco > 1) {
    for (int i = 1; i <= tco; i++) {
      int u = wzj[i];
      int v = sagitta[(i % tco) + 1].size() == 0 ? wzj[(i % tco) + 1]
                                                 : sagitta[(i % tco) + 1][0];
      printf("%d %d\n", u, v);
    }
  }
  for (int i = 1; i <= tco; i++)
    for (int j = (tco > 1); j < (int)sagitta[i].size(); j++)
      printf("%d %d\n", wzj[i], sagitta[i][j]);
  return 0;
}
