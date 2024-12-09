#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
vector<long long> adj[205];
vector<pair<long long, long long> > edge;
long long n, ans, pos, maxht, val1, val2, visited[205];
void comp(long long u, long long v, long long h) {
  long long i;
  long long maxi = 0;
  for (i = 0; i < adj[u].size(); i++) {
    long long x = adj[u][i];
    if (x != v) comp(x, u, h + 1);
  }
  if (h > maxht) {
    maxht = h;
    pos = u;
  }
}
void solve(long long u, long long p, long long h) {
  long long i;
  long long maxi = 0;
  for (i = 0; i < adj[u].size(); i++) {
    long long x = adj[u][i];
    if (x != p) comp(x, u, h + 1);
  }
  if (h > maxht) {
    maxht = h;
    pos = u;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long i;
  for (i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge.push_back(make_pair(u, v));
  }
  for (i = 0; i < n - 1; i++) {
    long long u = edge[i].first;
    long long v = edge[i].second;
    adj[v].erase(find((adj[v]).begin(), (adj[v]).end(), u));
    adj[u].erase(find((adj[u]).begin(), (adj[u]).end(), v));
    maxht = -1;
    comp(u, -1, 0);
    maxht = -1;
    solve(pos, -1, 0);
    val1 = maxht;
    maxht = -1;
    comp(v, -1, 0);
    maxht = -1;
    solve(pos, -1, 0);
    val2 = maxht;
    ans = max(ans, val1 * val2);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << ans;
  return 0;
}
