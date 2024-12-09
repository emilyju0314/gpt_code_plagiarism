#include <bits/stdc++.h>
#pragma GCC optimise("ofast")
#pragma GCC optimise("unroll-loops")
using namespace std;
const int N = 200000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000000000000000;
const long long LOG = 25;
int n, m, k, s1, s2, f, l[N], r[N], val[N], node[N], nodeu[N], NODE[N];
long long dis[N], dis2[N], dis3[N];
vector<pair<int, int>> G[N], Gin[N];
inline void DJ(int v) {
  memset(dis, 63, sizeof dis);
  dis[v] = 0;
  set<pair<long long, int>> st;
  st.insert({dis[v], v});
  while (st.size()) {
    pair<long long, int> fr = *st.begin();
    st.erase(st.begin());
    for (auto u : G[fr.second]) {
      if (dis[u.first] > fr.first + val[u.second]) {
        st.erase({dis[u.first], u.first});
        dis[u.first] = fr.first + val[u.second];
        st.insert({dis[u.first], u.first});
      }
    }
  }
}
inline void DJ2(int v) {
  memset(dis2, 63, sizeof dis2);
  dis2[v] = 0;
  set<pair<long long, int>> st;
  st.insert({0, v});
  while (st.size()) {
    pair<long long, int> fr = *st.begin();
    st.erase(st.begin());
    for (auto u : G[fr.second]) {
      if (dis2[u.first] > fr.first + val[u.second]) {
        st.erase({dis2[u.first], u.first});
        dis2[u.first] = fr.first + val[u.second];
        st.insert({dis2[u.first], u.first});
      }
    }
  }
}
bool cmp(int x, int y) { return dis[node[x]] < dis[node[y]]; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> s1 >> s2 >> f;
  for (int i = 1; i <= m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    G[v].push_back({u, i});
    Gin[u].push_back({v, i});
    val[i] = w;
  }
  for (int i = m + 1; i <= m + k; i++) {
    int v, u, L, R;
    cin >> v >> u >> L >> R;
    l[i] = L, r[i] = R;
    node[i] = v;
    nodeu[i] = u;
    G[v].push_back({u, i});
    Gin[u].push_back({v, i});
    val[i] = R;
  }
  DJ(s1), DJ2(s2);
  for (int i = m + 1; i <= m + k; i++) {
    if (dis[node[i]] < dis2[node[i]] && val[i] != l[i]) {
      val[i] = l[i];
      DJ(s1);
      DJ2(s2);
      i = m;
    }
  }
  if (dis[f] < dis2[f]) {
    cout << "WIN\n";
    for (int i = m + 1; i <= m + k; i++) cout << val[i] << ' ';
    return 0;
  }
  if (dis[f] == dis2[f]) {
    cout << "DRAW\n";
    for (int i = m + 1; i <= m + k; i++) cout << val[i] << ' ';
    return 0;
  }
  cout << "LOSE";
  return 0;
}
