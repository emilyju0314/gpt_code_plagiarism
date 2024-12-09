#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> G[N];
vector<int> r_G[N];
int vis[N + 10];
int par[2][N + 10];
int src;
int n, m;
bool cycle(int u) {
  if (vis[u] == -1) return true;
  if (vis[u] == 1) return false;
  vis[u] = -1;
  for (int v : G[u]) {
    if (cycle(v)) return true;
  }
  vis[u] = 1;
  return false;
}
void BFS() {
  queue<pair<int, int> > Q;
  Q.push(make_pair(0, src));
  par[0][src] = -1;
  while (not Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    int p = now.first, u = now.second;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (not par[p ^ 1][v]) {
        par[p ^ 1][v] = u;
        Q.push(make_pair(p ^ 1, v));
      }
    }
  }
}
vector<int> seq;
void path() {
  for (int u = 1; u <= n; u++) {
    if (par[1][u] && G[u].size() == 0) {
      int p = 1, v = u;
      while (v != -1) {
        seq.push_back(v);
        v = par[p][v];
        p ^= 1;
      }
      reverse(seq.begin(), seq.end());
      break;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int u = 1; u <= n; u++) {
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
      int v;
      scanf("%d", &v);
      G[u].push_back(v);
      r_G[v].push_back(i);
    }
  }
  scanf("%d", &src);
  BFS();
  path();
  if (!seq.size()) {
    if (cycle(src))
      printf("Draw\n");
    else
      printf("Lose\n");
  } else {
    printf("Win\n");
    for (int i = 0; i < seq.size(); i++) printf("%d ", seq[i]);
    printf("\n");
  }
  return 0;
}
