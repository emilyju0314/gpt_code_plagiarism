#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> entrada(n), sortida(n);
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    entrada[i] = x * 4 + y * 2 + z;
  }
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    sortida[i] = x * 4 + y * 2 + z;
    sortida[i] &= entrada[i];
  }
  vector<vector<int> > nodes(64);
  for (int i = 0; i < n; ++i) {
    nodes[entrada[i] * 8 + sortida[i]].push_back(i);
  }
  vector<bool> vis(64, false);
  vector<bool> marcat(n, false);
  queue<int> q;
  q.push(63);
  vis[63] = true;
  vector<pair<int, int> > sol;
  vector<int> surt(3, -1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int entr = x / 8, sort = x % 8;
    if (nodes[x].size() > 0) {
      for (int i = 0; i + 1 < nodes[x].size(); ++i) {
        sol.push_back({nodes[x][i], nodes[x][i + 1]});
      }
      int use = nodes[x].back();
      marcat[use] = true;
      for (int z = 0; z < 3; ++z) {
        if (sort == (1 << z) and surt[z] == -1) {
          surt[z] = use;
          for (int t = 1; t <= 2; ++t) {
            int nxt = (z + t) % 3;
            if (surt[nxt] != -1) {
              int cosa = (1 << z) + (1 << nxt);
              int tmp = cosa * 8 + cosa;
              if (!vis[tmp] and nodes[tmp].size() != 0) {
                int vei = tmp;
                vis[vei] = true;
                if (nodes[vei].size() != 0) {
                  q.push(vei);
                  sol.push_back({use, nodes[vei][0]});
                  sol.push_back({surt[nxt], nodes[vei][0]});
                  vis[vei] = true;
                }
              } else {
                for (int s = 0; s < 8; ++s) {
                  if ((s & cosa) == s) {
                    int vei = cosa * 8 + s;
                    if (!vis[vei]) {
                      vis[vei] = true;
                      if (nodes[vei].size() != 0) {
                        q.push(vei);
                        sol.push_back({use, nodes[vei][0]});
                        sol.push_back({surt[nxt], nodes[vei][0]});
                        vis[vei] = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      for (int s = 0; s < 8; ++s) {
        if ((s & sort) == s) {
          int vei = sort * 8 + s;
          if (!vis[vei]) {
            vis[vei] = true;
            if (nodes[vei].size() != 0) {
              q.push(vei);
              sol.push_back({use, nodes[vei][0]});
              vis[vei] = true;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < 64; ++i) {
    if (!vis[i] and nodes[i].size() > 0) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < n; ++i) {
    if (marcat[i])
      cout << 1 << " ";
    else
      cout << 0 << " ";
  }
  cout << endl;
  cout << sol.size() << endl;
  for (auto x : sol) cout << x.first + 1 << " " << x.second + 1 << endl;
}
