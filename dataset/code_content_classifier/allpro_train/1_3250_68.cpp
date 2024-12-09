#include <bits/stdc++.h>
using namespace std;
vector<long long> G[200005];
bool Hash[200005];
long long depth[200005];
bool visited[200005];
long long Sum[200005];
long long Max[200005];
void dfs(long long src) {
  visited[src] = 1;
  if (Hash[src]) Sum[src]++;
  for (long long i = 0; i < G[src].size(); ++i) {
    if (visited[G[src][i]]) continue;
    depth[G[src][i]] = depth[src] + 1;
    dfs(G[src][i]);
    if (Sum[G[src][i]] > Sum[Max[src]]) Max[src] = G[src][i];
    Sum[src] += Sum[G[src][i]];
  }
}
int main() {
  long long n, k, ans = 0;
  cin >> n >> k;
  for (long long i = 0; i < 2 * k; ++i) {
    long long u;
    cin >> u;
    Hash[u]++;
  }
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  for (long long i = 1; i <= n; ++i) {
    if (Hash[i]) ans += depth[i];
  }
  long long curr = 1;
  while (k) {
    if (Sum[curr] - 2 * Sum[Max[curr]] >= 0)
      k = 0;
    else if (Sum[curr] - Sum[Max[curr]] >= k)
      k = 0;
    else {
      k = k - Sum[curr] + Sum[Max[curr]];
      ans = ans - 2 * k;
      curr = Max[curr];
    }
  }
  cout << ans;
  return 0;
}
