#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const ll inf = 1e15;

int n, m;
vector<pair<int, ll>> g[N];

ll dist[N][2][2];

struct ver {
  int v, u1, u2;
  bool operator< (const ver &a) const {
    ll d1 = dist[v][u1][u2], d2 = dist[a.v][a.u1][a.u2];
    if (d1 != d2) return d1 < d2;
    if (v != a.v) return v < a.v;
    if (u1 != a.u1) return u1 < a.u1;
    return u2 < a.u2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }

  for (int i = 0; i < n; ++i)
    dist[i][0][0] = dist[i][0][1] = dist[i][1][0] = dist[i][1][1] = inf;
  dist[0][0][0] = 0;
  set<ver> st;
  st.insert({0, 0, 0});
  while (!st.empty()) {
    ver v = *(st.begin());
    st.erase(st.begin());
    for (auto &e : g[v.v]) {
      for (int a1 = 0; a1 <= 1 - v.u1; ++a1) {
        for (int a2 = 0; a2 <= 1 - v.u2; ++a2) {
          ll dto = dist[e.first][v.u1+a1][v.u2+a2];
          ll nd = dist[v.v][v.u1][v.u2] + e.second;
          if (a1) nd -= e.second;
          if (a2) nd += e.second;
          if (dto > nd) {
            ver g = {e.first, v.u1 + a1, v.u2 + a2};
            if (st.find(g) != st.end()) st.erase(g);
            dist[g.v][g.u1][g.u2] = nd;
            st.insert(g);
          }
        }
      }
    }
  }

  for (int i = 1; i < n; ++i)
    cout << dist[i][1][1] << ' ';

}