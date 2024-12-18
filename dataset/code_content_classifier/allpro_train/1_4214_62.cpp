#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N + 1];
vector<int> color(N + 1);
vector<bool> visited(N + 1);
void getw(vector<int> *pp) {
  int l;
  cin >> l;
  pp->clear();
  while (l-- > 0) {
    int s;
    cin >> s;
    pp->push_back(s);
  }
}
bool yes = true;
void dfs(int u) {
  if (color[u] == 2) {
    yes = false;
    return;
  }
  if (visited[u]) return;
  visited[u] = true;
  color[u] = 1;
  for (int v : adj[u]) dfs(v);
}
int main() {
  int w, n;
  cin >> w >> n;
  vector<int> p_, q_, *pp = &p_, *qq = &q_;
  getw(pp);
  for (int h = 1; h < w; h++) {
    getw(qq);
    bool same = true;
    int l = min(pp->size(), qq->size());
    for (int i = 0; i < l; i++) {
      int u = (*pp)[i];
      int v = (*qq)[i];
      if (u != v) {
        if (u < v)
          adj[v].push_back(u);
        else {
          if (color[u] == 2 || color[v] == 1) {
            cout << "No" << endl;
            return 0;
          }
          color[u] = 1;
          color[v] = 2;
        }
        same = false;
        break;
      }
    }
    if (same && pp->size() > qq->size()) {
      cout << "No" << endl;
      return 0;
    }
    auto tmp = pp;
    pp = qq;
    qq = tmp;
  }
  for (int u = 1; u <= n; u++)
    if (color[u] == 1) dfs(u);
  cout << (yes ? "Yes" : "No") << endl;
  if (yes) {
    int k = 0;
    vector<int> cap;
    for (int u = 1; u <= n; u++)
      if (color[u] == 1) {
        k++;
        cap.push_back(u);
      }
    cout << k << endl;
    for (int u : cap) cout << u << ' ';
    cout << endl;
  }
  return 0;
}
