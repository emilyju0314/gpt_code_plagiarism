#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > adj;
long long int n;
vector<long long int> vis(1005, -1);
void dfs(long long int cur) {
  vis[cur] = 1;
  for (long long int i = 0; i < n; i++) {
    if (vis[i] == -1 &&
        (adj[i].first == adj[cur].first || adj[i].second == adj[cur].second)) {
      dfs(i);
    }
  }
}
void solve() {
  cin >> n;
  adj.resize(n);
  for (long long int i = 0; i < n; i++) {
    cin >> adj[i].first >> adj[i].second;
  }
  long long int co = 0;
  for (long long int i = 0; i < n; i++) {
    if (vis[i] == -1) {
      dfs(i);
      co++;
    }
  }
  cout << co - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
