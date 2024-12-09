#include <bits/stdc++.h>
using namespace std;
struct Node {
  int num, pre;
  Node(int _num = 0, int _pre = 0) {
    num = _num;
    pre = _pre;
  }
};
int flag = 0;
int cnt = 0;
vector<bool> vi;
void dfs(vector<vector<vector<int> > > &arc, int n, int u, int v, int c,
         int pre) {
  vi[u] = true;
  int ii = 0, jj = 0;
  if (u == v) {
    cnt++;
    flag = 1;
    return;
  }
  for (jj = 1; jj <= n; jj++) {
    if (flag == 1) break;
    if (vi[jj] == false &&
        find(arc[u][jj].begin(), arc[u][jj].end(), c) != arc[u][jj].end()) {
      dfs(arc, n, jj, v, c, u);
    }
  }
}
int main() {
  int n = 0, m = 0;
  while (cin >> n >> m) {
    vector<int> v_tmp;
    vector<vector<vector<int> > > arc(n + 1,
                                      vector<vector<int> >(n + 1, v_tmp));
    int i = 0, j = 0;
    for (i = 1; i <= m; i++) {
      int a = 0, b = 0, c = 0;
      cin >> a >> b >> c;
      arc[a][b].push_back(c);
      arc[b][a].push_back(c);
    }
    int q = 0;
    cin >> q;
    int ii = 0, jj = 0, kk = 0;
    for (i = 0; i < q; i++) {
      int u = 0, v = 0;
      cin >> u >> v;
      if (u > v) {
        int tmp = u;
        u = v;
        v = tmp;
      }
      cnt = 0;
      for (ii = 1; ii <= m; ii++) {
        flag = 0;
        vi = vector<bool>(n + 1, false);
        dfs(arc, n, u, v, ii, -1);
      }
      cout << cnt << endl;
    }
  }
}
