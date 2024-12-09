#include <bits/stdc++.h>
using namespace std;
vector<int> Bad[100005];
int from[100005], to[100005];
int badEdge[100005];
int deg[100005];
int sz[100005];
int childEdge[100005];
int childN[100005];
int parentEdge[100005];
vector<int> adj[100005];
vector<int> adjEdge[100005];
struct UF {
  int a[100005];
  int find(int x) {
    if (a[x] == -1) return x;
    return a[x] = find(a[x]);
  }
  void join(int c, int b, int ind) {
    int C = find(c), B = find(b);
    if (C == B) return;
    a[C] = B;
    adj[b].push_back(c);
    adj[c].push_back(b);
    adjEdge[b].push_back(ind);
    adjEdge[c].push_back(ind);
    ++deg[b];
    ++deg[c];
    ++childN[b];
  }
  bool sameSet(int b, int c) { return find(b) == find(c); }
} uf;
struct Ans {
  int a, b, c;
  Ans(int _a, int _b, int _c) {
    a = _a;
    b = _b;
    c = _c;
  }
};
vector<Ans*> ans;
bool val[100005];
bool useFrom[100005];
bool processed[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    uf.a[i] = -1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", from + i, to + i);
    --from[i];
    --to[i];
    val[from[i]] ^= 1;
    useFrom[i] = 1;
    uf.join(from[i], to[i], i);
  }
  queue<int> leaves;
  for (int i = 0; i < n; ++i)
    if (deg[i] <= 1) leaves.push(i);
  while (!leaves.empty()) {
    int cur = leaves.front();
    leaves.pop();
    if (!deg[cur]) {
      if (val[cur]) {
        printf("No solution\n");
        return 0;
      }
      continue;
    }
    processed[cur] = 1;
    int parent;
    int parentEdge;
    for (int i = 0; i < adj[cur].size(); ++i)
      if (!processed[adj[cur][i]]) {
        parent = adj[cur][i];
        parentEdge = adjEdge[cur][i];
      }
    --deg[parent];
    if (deg[parent] == 1) leaves.push(parent);
    if (!val[cur]) continue;
    val[parent] ^= 1;
    useFrom[parentEdge] ^= 1;
  }
  for (int i = 1; i <= m; ++i) {
    if (useFrom[i]) {
      Bad[from[i]].push_back(to[i]);
    } else
      Bad[to[i]].push_back(from[i]);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < Bad[i].size(); j += 2) {
      printf("%d %d %d\n", Bad[i][j] + 1, i + 1, Bad[i][j + 1] + 1);
    }
  return 0;
}
