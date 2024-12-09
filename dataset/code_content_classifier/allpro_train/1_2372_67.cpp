#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
const long double EPS = 1e-9;
const int INF = 1 << 28;
const long double PI = fabsl(atan2l(0.0, -1.0));
const int MAXN = 11111;
map<string, int> idx;
vector<string> names;
inline int addPerson(const string &name) {
  if (idx.find(name) != idx.end()) return idx[name];
  idx[name] = names.size();
  names.push_back(name);
  return idx[name];
}
int n;
int m;
vector<int> g[MAXN];
char name1[55];
char name2[55];
void load() {
  scanf("%d\n", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s%s", name1, name2);
    int u = addPerson(name1);
    int v = addPerson(name2);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  n = names.size();
}
int color[MAXN];
int ccnt[MAXN];
void dfs(int v, int c) {
  color[v] = c;
  ccnt[c]++;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (color[to] == -1) dfs(to, c);
  }
}
int best[MAXN];
int answer[MAXN];
int mark[MAXN];
int reorder[MAXN];
void solveForComponent(int c) {
  vector<int> vert;
  for (int i = 0; i < n; i++) {
    if (color[i] == c) {
      reorder[i] = vert.size();
      vert.push_back(i);
    }
  }
  vector<vector<int> > a(vert.size(), vector<int>(vert.size(), 0));
  vector<vector<int> > cnt(vert.size(), vector<int>(vert.size(), 0));
  for (int i = 0; i < (int)vert.size(); i++) {
    int u = vert[i];
    int uu = reorder[u];
    for (int j = 0; j < (int)g[u].size(); j++) {
      int v = g[u][j];
      int vv = reorder[v];
      a[uu][vv] = a[vv][uu] = 1;
    }
  }
  for (int i = 0; i < (int)vert.size(); i++) {
    int w = vert[i];
    for (int j = 0; j < (int)g[w].size(); j++) {
      int u = g[w][j];
      int uu = reorder[u];
      for (int k = 0; k < (int)g[w].size(); k++) {
        int v = g[w][k];
        int vv = reorder[v];
        if (u == v || a[uu][vv]) continue;
        cnt[uu][vv]++;
        cnt[vv][uu]++;
      }
    }
  }
  for (int i = 0; i < (int)vert.size(); i++) {
    int u = vert[i];
    int uu = reorder[u];
    for (int j = 0; j < (int)vert.size(); j++) {
      int v = vert[j];
      int vv = reorder[v];
      if (uu == vv || a[uu][vv]) continue;
      if (cnt[uu][vv] > best[u]) {
        best[u] = cnt[uu][vv];
        answer[u] = 0;
      }
      if (cnt[uu][vv] == best[u]) answer[u]++;
    }
  }
}
void solve() {
  int cc = 0;
  memset(color, -1, sizeof(color));
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) dfs(i, cc++);
  }
  for (int c = 0; c < cc; c++) solveForComponent(c);
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    if (best[i] == 0) answer[i] += n - ccnt[color[i]];
    printf("%s %d\n", names[i].c_str(), answer[i]);
  }
}
int main() {
  load();
  solve();
  return 0;
}
