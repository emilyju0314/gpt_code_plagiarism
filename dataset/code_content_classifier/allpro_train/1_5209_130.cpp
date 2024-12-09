#include <bits/stdc++.h>
using namespace std;
void Test_Case() {
  int n, m;
  cin >> n >> m;
  vector<set<int> > gr(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    gr[u].insert(v);
    gr[v].insert(u);
  }
  bool cont = 1;
  int ans = 0;
  while (cont) {
    bool cur = 0;
    set<int> c;
    for (int i = 1; i < n + 1; i++) {
      if (c.find(i) != c.end()) continue;
      if (gr[i].size() == 1) {
        cur = 1;
        int to = *gr[i].begin();
        gr[i].erase(to);
        gr[to].erase(i);
        c.insert(to);
      }
    }
    if (cur)
      ++ans;
    else
      cont = 0;
  }
  cout << ans << "\n";
}
int main() {
  int TC = 1;
  while (TC--) Test_Case();
  return 0;
}
