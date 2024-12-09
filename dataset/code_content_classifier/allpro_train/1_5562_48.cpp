#include <bits/stdc++.h>
using namespace std;
const int MM = 500013;
vector<int> W[MM];
vector<pair<int, int> > ans;
vector<int> Deb[MM], Path;
int N, vis[MM];
bool DFS(int w, int d = 1) {
  if (d >= N) {
    Path.push_back(w);
    return true;
  }
  vis[w] = true;
  Deb[d].push_back(w);
  for (const int &v : W[w])
    if (!vis[v]) {
      if (DFS(v, d + 1)) {
        Path.push_back(w);
        return true;
      }
    }
  return false;
}
void solve() {
  int a, b, n, m;
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) W[i].clear(), Deb[i].clear(), vis[i] = 0;
  ans.clear();
  Path.clear();
  N = (n + 1) / 2;
  for (int i = (1); i <= (m); ++i) {
    cin >> a >> b;
    W[a].push_back(b);
    W[b].push_back(a);
  }
  if (DFS(1)) {
    cout << "PATH\n";
    cout << Path.size() << "\n";
    for (const int &v : Path) cout << v << " ";
    cout << "\n";
  } else {
    for (int i = (1); i <= (N); ++i)
      for (int j = 0; j + 1 < Deb[i].size(); j += 2)
        ans.push_back({Deb[i][j], Deb[i][j + 1]});
    cout << "PAIRING\n";
    cout << ans.size() << "\n";
    for (const pair<int, int> &v : ans)
      cout << v.first << " " << v.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int Z;
  cin >> Z;
  while (Z--) solve();
  return 0;
}
