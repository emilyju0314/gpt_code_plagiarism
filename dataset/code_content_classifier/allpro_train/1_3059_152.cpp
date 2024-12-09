#include <bits/stdc++.h>
using namespace std;
int k, all = 0;
int main() {
  vector<vector<int> > g;
  vector<int> color;
  map<int, set<int> > used;
  int n, m, ncol = 1;
  scanf("%d%d", &n, &m);
  color.resize(n);
  g.resize(n);
  int maxcol = 0, col = 1E+9;
  for (int i = 0; i < n; i++) {
    scanf("%d", &color[i]);
    if (color[i] < col) col = color[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (color[a - 1] != color[b - 1]) {
      g[b - 1].push_back(a - 1);
      g[a - 1].push_back(b - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      int to = g[i][j];
      used[color[i]].insert(color[to]);
    }
    if (maxcol < used[color[i]].size() ||
        (maxcol == used[color[i]].size() && color[i] < col)) {
      col = color[i];
      maxcol = used[color[i]].size();
    }
  }
  printf("%d", col);
  return 0;
}
