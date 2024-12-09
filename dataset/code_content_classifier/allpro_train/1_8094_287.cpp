#include <bits/stdc++.h>
using namespace std;
int a[1000005];
pair<int, int> dis[100005];
pair<pair<int, int>, int> ed[100005];
int par[100005];
map<int, bool> tr[100005];
vector<pair<int, int>> adj[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j, k, l, m, n, t, r, cnt;
  int flag = 0;
  long long ans = 0, an = 0;
  t = 1;
  while (t--) {
    cin >> n >> m;
    int u, v, w;
    for (i = 0; i < m; i++) {
      cin >> u >> v >> w;
      w = 1 - w;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
      ed[i] = make_pair(make_pair(u, v), w);
    }
    for (i = 1; i <= n; i++) {
      dis[i] = make_pair((int)1e9, (int)1e9);
    }
    multiset<pair<pair<int, int>, int>> se;
    se.insert(make_pair(make_pair(0, 0), 1));
    while (!se.empty()) {
      pair<int, int> w = se.begin()->first;
      int node = se.begin()->second;
      se.erase(se.begin());
      for (pair<int, int> it : adj[node]) {
        pair<int, int> w2 = make_pair(1 + w.first, it.second + w.second);
        if (w2 < dis[it.first]) {
          dis[it.first] = w2;
          par[it.first] = node;
          se.insert(make_pair(w2, it.first));
        }
      }
    }
    int node = n;
    while (node != 1) {
      tr[node][par[node]] = true;
      tr[par[node]][node] = true;
      node = par[node];
    }
    vector<pair<pair<int, int>, int>> fin;
    for (int i = 0; i < m; i++) {
      u = ed[i].first.first;
      v = ed[i].first.second;
      w = ed[i].second;
      if (w == 1) {
        if (tr[u][v]) {
          fin.push_back(make_pair(make_pair(u, v), w));
        }
      } else {
        if (!tr[u][v]) {
          fin.push_back(make_pair(make_pair(u, v), w));
        }
      }
    }
    cout << (int)fin.size() << endl;
    for (int i = 0; i < (int)fin.size(); i++) {
      cout << fin[i].first.first << " " << fin[i].first.second << " "
           << fin[i].second << endl;
    }
  }
}
