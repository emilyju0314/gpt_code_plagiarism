#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(104);
int main() {
  int n, m, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> x;
      g[i].push_back(x);
    }
  }
  for (int i = 0; i < n; i++) {
    bool vis[105] = {0};
    for (int j = 0; j < g[i].size(); j++) vis[g[i][j]] = 1;
    bool f = 0;
    for (int j = 0; j < n; j++)
      if (j != i && g[j].size() <= g[i].size()) {
        bool f1 = 1;
        for (int k = 0; k < g[j].size(); k++)
          if (vis[g[j][k]] != 1) f1 = 0;
        if (f1) f = 1;
      }
    if (f == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
