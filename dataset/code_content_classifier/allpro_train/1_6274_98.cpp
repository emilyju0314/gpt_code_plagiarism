#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b;
bool zly[100010];
int ok, u, v;
vector<int> order, graf[100010];
set<pair<double, int> > se;
int oks[100010], best_pos;
double best_res;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a;
    zly[a] = true;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!zly[i]) {
      ok = 0;
      for (int j = 0; j < graf[i].size(); j++) {
        if (!zly[graf[i][j]]) ok++;
      }
      oks[i] = ok;
      se.insert(make_pair(double(ok) / double(graf[i].size()), i));
    }
  }
  best_res = -1.;
  best_pos = 0;
  while (se.size() > 0) {
    if (se.begin()->first > best_res) {
      best_res = se.begin()->first;
      best_pos = order.size();
    }
    v = se.begin()->second;
    order.push_back(v);
    se.erase(se.begin());
    for (int i = 0; i < graf[v].size(); i++) {
      u = graf[v][i];
      if (!zly[u]) {
        se.erase(make_pair(double(oks[u]) / double(graf[u].size()), u));
        oks[u]--;
        se.insert(make_pair(double(oks[u]) / double(graf[u].size()), u));
      }
    }
    zly[v] = true;
  }
  cout << order.size() - best_pos << endl;
  for (int i = best_pos; i < order.size(); i++) {
    cout << order[i] << " ";
  }
  cout << endl;
}
