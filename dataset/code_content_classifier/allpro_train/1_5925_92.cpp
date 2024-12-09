#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, A, B, m;
int a[200010], opa[200010], opb[200010];
vector<int> G[200010];
vector<int> rG[200010];
vector<int> vs;
bool used[200010];
int cmp[200010];
void addedge(int u, int v) {
  G[u].push_back(v);
  rG[v].push_back(u);
}
void init() {
  for (int i = 0; i <= n; ++i) {
    G[i].clear();
    rG[i].clear();
  }
}
void dfs(int u) {
  used[u] = true;
  for (int i = 0; i < G[u].size(); ++i) {
    if (!used[G[u][i]]) dfs(G[u][i]);
  }
  vs.push_back(u);
}
void rdfs(int u, int k) {
  used[u] = true;
  cmp[u] = k;
  for (int i = 0; i < rG[u].size(); ++i) {
    if (!used[rG[u][i]]) rdfs(rG[u][i], k);
  }
}
int scc() {
  memset(used, 0, sizeof(used));
  vs.clear();
  for (int i = 0; i < n; ++i) {
    if (!used[i]) dfs(i);
  }
  memset(used, 0, sizeof(used));
  int k = 0;
  for (int i = vs.size() - 1; i >= 0; --i) {
    if (!used[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}
int col[200010];
void build() {
  for (int i = 0; i < m; ++i) {
    int x = opa[i];
    int y = opb[i];
    if (opa[i] >= 0 && opb[i] >= 0) {
      addedge(i, x);
      addedge(i, y);
      addedge(i + m, x + m);
      addedge(i + m, y + m);
    } else if (opa[i] < 0) {
      addedge(i + m, y + m);
      addedge(i, i + m);
    } else if (opb[i] < 0) {
      addedge(i, x);
      addedge(i + m, i);
    }
  }
}
void solve() {
  build();
  int k = scc();
  for (int i = 0; i < m; ++i) {
    if (cmp[i] == cmp[m + i]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  for (int i = 0; i < m; ++i) {
    if (cmp[i] > cmp[i + m]) {
      col[i] = 0;
    } else {
      col[i] = 1;
    }
    printf("%d ", col[i]);
  }
  printf("\n");
}
int main() {
  while (scanf("%d%d%d", &m, &A, &B) != EOF) {
    mp.clear();
    for (int i = 0; i < m; ++i) {
      scanf("%d", &a[i]);
      mp[a[i] + 1e9 + 10] = i + 1;
      opa[i] = opb[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
      if (mp[A - a[i] + 1e9 + 10] > 0) {
        opa[i] = mp[A - a[i] + 1e9 + 10] - 1;
      }
      if (mp[B - a[i] + 1e9 + 10] > 0) {
        opb[i] = mp[B - a[i] + 1e9 + 10] - 1;
      }
    }
    init();
    n = 2 * m;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (opa[i] < 0 && opb[i] < 0) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      printf("NO\n");
      continue;
    }
    solve();
  }
}
