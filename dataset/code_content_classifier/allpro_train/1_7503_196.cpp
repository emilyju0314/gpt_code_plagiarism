#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using li = __int128;
using ull = unsigned long long;
using uli = unsigned __int128;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
void doReplace() {}
template <typename T, typename U, typename... Vs>
void doReplace(T& t, const U& u, Vs&&... vs) {
  t = u;
  doReplace(vs...);
}
template <typename T, typename... Us>
T maxim(T& was, const T& cand, Us&&... us) {
  if (was < cand) {
    was = cand;
    doReplace(us...);
  }
  return was;
}
template <typename T, typename... Us>
T minim(T& was, const T& cand, Us&&... us) {
  if (was > cand) {
    was = cand;
    doReplace(us...);
  }
  return was;
}
const int dx4[] = {1, 0, -1, 0};
const int dy4[] = {0, -1, 0, 1};
const int dx8[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy8[] = {1, 0, -1, -1, -1, 0, 1, 1};
const int dx_knight[] = {2, 1, 2, 1, -2, -1, -2, -1};
const int dy_knight[] = {1, 2, -1, -2, -1, -2, 1, 2};
inline bool isValidCell(int r, int c, int n, int m) {
  return r >= 0 && r < n && c >= 0 && c < m;
}
int g[5][5];
vector<int> adj[5];
void dfs(bool vis[], int len, int v, int start, int& ret) {
  vis[v] = true;
  if (len == 0) {
    vis[v] = false;
    for (int it : adj[v]) {
      if (it == start) {
        ret++;
        return;
      }
    }
    return;
  }
  for (int i = 0; i < 5; i++) {
    bool path = false;
    for (int it : adj[v]) {
      if (it == i) {
        path = true;
      }
    }
    if (path && !vis[i]) {
      dfs(vis, len - 1, i, start, ret);
    }
  }
  vis[v] = false;
}
int cycles(int len) {
  bool vis[5];
  for (int i = 0; i < 5; i++) vis[i] = false;
  int ret = 0;
  for (int i = 0; i < 5 - (len - 1); i++) {
    dfs(vis, len - 1, i, i, ret);
    vis[i] = true;
  }
  return (ret / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  memset(g, 0, sizeof(g));
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = g[v][u] = 1;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (g[i][j] == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  int yes = cycles(3);
  for (int i = 0; i < 5; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (g[i][j] == 0) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  int no = cycles(3);
  if (yes > 0 || no > 0)
    cout << "WIN";
  else
    cout << "FAIL";
  return 0;
}
