#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
vector<int> adj[MAX], adj2[MAX];
int usd[MAX];
bool ciclo;
vector<vector<int> > comp;
vector<int> componente;
void dfs(int u) {
  usd[u] = 1;
  componente.push_back(u);
  for (int i = (0); i < (adj[u].size()); i++) {
    int v = adj[u][i];
    if (!usd[v]) dfs(v);
  }
}
void dfs2(int u) {
  usd[u] = 0;
  for (int i = (0); i < (adj2[u].size()); i++) {
    int v = adj2[u][i];
    if (usd[v] == -1) dfs2(v);
    if (usd[v] == 0) {
      ciclo = 1;
      break;
    } else
      continue;
  }
  usd[u] = 1;
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adj2[a].push_back(b);
  }
  memset(usd, 0, sizeof(usd));
  for (int i = (0); i < (n); i++) {
    if (!usd[i]) {
      componente.clear();
      dfs(i);
      comp.push_back(componente);
    }
  }
  memset(usd, -1, sizeof(usd));
  int ans = 0;
  for (int i = (0); i < (comp.size()); i++) {
    ciclo = 0;
    for (int j = (0); j < (comp[i].size()); j++) {
      int u = comp[i][j];
      if (usd[u] == -1) dfs2(u);
    }
    if (ciclo)
      ans += comp[i].size();
    else
      ans += (comp[i].size() - 1);
  }
  cout << ans << endl;
  return 0;
}
