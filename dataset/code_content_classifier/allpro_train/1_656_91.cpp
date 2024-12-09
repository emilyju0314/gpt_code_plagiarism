#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
vector<pair<int, int> > g[(300003)];
int N, M, C[(300003)], O, v = -1, a, b, Z[(300003)];
vector<int> o;
bool dfs(int u) {
  int X = C[u] == 1;
  Z[u]++;
  for (auto &h : g[u])
    if (!Z[h.first]++ && dfs(h.first)) o.push_back(h.second), ++X;
  return X & 1;
}
int main(void) {
  scanf("%d%d", &N, &M), ga(N, C);
  for (int i(0); i < N; i++) O += C[i] == 1, v = ~C[i] ? v : i;
  if (O & 1 && !~v) return puts("-1");
  for (int i(0); i < M; i++)
    scanf("%d%d", &a, &b), g[--a].push_back({--b, i}), g[b].push_back({a, i});
  dfs(~v ? v : 0), sort(o.begin(), o.end());
  printf("%lu\n", o.size());
  for (auto &h : o) printf("%d\n", h + 1);
  return 0;
}
