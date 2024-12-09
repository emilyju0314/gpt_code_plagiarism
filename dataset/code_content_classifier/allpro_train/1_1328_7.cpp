#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5;
int n, m, k;
vector<int> adj[MXN];
int du[MXN], del[MXN];
int cnt[MXN];
void work() {
  cin >> n >> m >> k;
  for (register int i = (0), LIM = (m); i < LIM; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v), adj[v].emplace_back(u);
    ++du[u], ++du[v];
  }
  int flag = 0;
  if (1ll * k * (k - 1) > 2 * m) flag = -1;
  set<pair<int, int> > Q;
  for (register int i = (1), LIM = (n + 1); i < LIM; ++i) {
    Q.insert(make_pair(du[i], i));
    sort(adj[i].begin(), adj[i].end());
  }
  vector<int> vs;
  while (!Q.empty() && flag == 0) {
    pair<int, int> u = *Q.begin();
    if (u.first == k - 1) {
      vs.clear();
      for (int v : adj[u.second]) {
        if (del[v] == 0) {
          vs.emplace_back(v);
        }
      }
      vs.emplace_back(u.second);
      flag = 2;
      for (int a : vs) {
        if (a == u.second) break;
        for (int b : vs) {
          if (a != b) {
            if (!binary_search(adj[a].begin(), adj[a].end(), b)) {
              flag = 0;
              break;
            }
          }
        }
        if (flag == 0) break;
      }
      if (flag == 0) {
        auto p = Q.lower_bound(make_pair(du[u.second], u.second));
        Q.erase(p);
        del[u.second] = 1;
        for (int v : adj[u.second]) {
          if (del[v]) continue;
          --du[v];
          auto p = Q.lower_bound(make_pair(du[v] + 1, v));
          Q.erase(p);
          Q.insert(make_pair(du[v], v));
        }
      }
    } else if (u.first >= k) {
      flag = 1;
    } else {
      auto p = Q.lower_bound(make_pair(du[u.second], u.second));
      Q.erase(p);
      del[u.second] = 1;
      for (int v : adj[u.second]) {
        if (del[v]) continue;
        --du[v];
        auto p = Q.lower_bound(make_pair(du[v] + 1, v));
        Q.erase(p);
        Q.insert(make_pair(du[v], v));
      }
    }
  }
  if (flag <= 0)
    printf("-1\n");
  else if (flag == 1) {
    printf("1 %d\n", Q.size());
    for (pair<int, int> x : Q) printf("%d ", x.second);
    printf("\n");
  } else {
    printf("2\n");
    for (int x : vs) printf("%d ", x);
    printf("\n");
  }
  for (register int i = (1), LIM = (n + 1); i < LIM; ++i) {
    adj[i].clear();
    du[i] = del[i] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tim;
  cin >> tim;
  for (int cas = 1; cas <= tim; ++cas) work();
  return 0;
}
