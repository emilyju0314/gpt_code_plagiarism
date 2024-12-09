#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> edges[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < (int)(m); i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = make_pair(--u, --v);
  }
  sort(edges, edges + m);
  set<int> a;
  for (int i = 0; i < (int)(n); i++) a.insert(i);
  vector<vector<int> > ret;
  while (!a.empty()) {
    int v = *a.begin();
    a.erase(v);
    vector<int> vs;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      vs.push_back(x);
      for (set<int>::iterator itr = a.begin(); itr != a.end();) {
        int y = *itr;
        if (binary_search(edges, edges + m, make_pair(x, y)) ||
            binary_search(edges, edges + m, make_pair(y, x)))
          ++itr;
        else
          a.erase(itr++), q.push(y);
      }
    }
    ret.push_back(vs);
  }
  cout << ret.size() << endl;
  for (int i = 0; i < (int)(ret.size()); i++) {
    cout << ret[i].size() << " ";
    for (int j = 0; j < (int)(ret[i].size()); j++) cout << ret[i][j] + 1 << " ";
    cout << endl;
  }
  return 0;
}
