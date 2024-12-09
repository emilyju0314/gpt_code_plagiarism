#include <bits/stdc++.h>
using namespace std;
int N, M;
int v[100005];
vector<int> e[100005], e2[100005];
bool f1[100005], f2[100005];
void dfs1(int u) {
  f1[u] = 1;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (!f1[v]) dfs1(v);
  }
}
void dfs2(int u) {
  f2[u] = 1;
  if (v[u] == 1) return;
  for (int i = 0; i < e2[u].size(); i++) {
    int v = e2[u][i];
    if (!f2[v]) dfs2(v);
  }
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", &v[i]);
  for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    e[u].push_back(v);
    e2[v].push_back(u);
  }
  memset(f1, false, sizeof(f1));
  memset(f2, false, sizeof(f2));
  for (int i = 0; i < N; i++)
    if (!f1[i] && v[i] == 1) dfs1(i);
  for (int i = 0; i < N; i++)
    if (!f2[i] && v[i] == 2) dfs2(i);
  for (int i = 0; i < N; i++) printf("%d\n", f1[i] & f2[i]);
  return 0;
}
