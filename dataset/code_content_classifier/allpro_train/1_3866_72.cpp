#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 300100;
vector<int> s1, s2;
int fa[N][30], dep[N];
int head[N], cnt;
struct edge {
  int to, next;
} e[N << 1];
void adde(int a, int b) {
  e[++cnt].to = b;
  e[cnt].next = head[a];
  head[a] = cnt;
}
void addnode(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i = 1; i <= 20 && fa[u][i - 1]; i++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--)
    if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
  if (u == v) return v;
  for (int i = 20; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int dis(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)] * 2; }
int main() {
  scanf("%d", &n);
  n++;
  addnode(1, 0);
  s1.push_back(1);
  int u, maxd = 0;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &u);
    addnode(i, u);
    int d1 = s1.empty() ? 0 : dis(i, s1[0]),
        d2 = s2.empty() ? 0 : dis(i, s2[0]);
    if (max(d1, d2) > maxd) {
      maxd = max(d1, d2);
      if (maxd == d1) {
        for (int j = 0; j < s2.size(); j++)
          if (dis(s2[j], i) == d1) s1.push_back(s2[j]);
        s2.clear();
      } else {
        for (int j = 0; j < s1.size(); j++)
          if (dis(s1[j], i) == d2) s2.push_back(s1[j]);
        s1.clear();
      }
    }
    if (maxd == max(d1, d2))
      if (maxd == d1)
        s2.push_back(i);
      else
        s1.push_back(i);
    printf("%d\n", s1.size() + s2.size());
  }
  return 0;
}
