#include <bits/stdc++.h>
using namespace std;
void null() { return; }
const int maxn = 1e5 + 7;
int cnt_sub[maxn];
char res[maxn];
vector<int> g[maxn];
int seen = 0;
int count_subtree(int v, int p) {
  seen++;
  cnt_sub[v] = 1;
  for (auto u : g[v])
    if (u != p) cnt_sub[v] += count_subtree(u, v);
  return cnt_sub[v];
}
int find_centroid(int v, int p) {
  for (auto u : g[v])
    if (u != p && cnt_sub[u] > seen / 2) return find_centroid(u, v);
  return v;
}
void decomposs(int v, char c) {
  if (c > 'Z') {
    cout << "Impossible!";
    exit(0);
  }
  seen = 0;
  count_subtree(v, -1);
  int centroid = find_centroid(v, -1);
  res[centroid] = c;
  for (auto u : g[centroid]) {
    for (int i = 0; i < g[u].size(); i++) {
      if (g[u][i] == centroid) {
        g[u].erase(g[u].begin() + i);
        decomposs(u, c + 1);
        break;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  decomposs(1, 'A');
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
