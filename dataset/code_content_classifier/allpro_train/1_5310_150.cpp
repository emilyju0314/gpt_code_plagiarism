#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = 3.14159265359;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  vector<int> ccs(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (ccs[i] == -1) {
      queue<int> q;
      q.push(i);
      ccs[i] = i;
      while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int j : graph[cur]) {
          if (ccs[j] == -1) {
            ccs[j] = i;
            q.push(j);
          }
        }
      }
    }
  }
  vector<vector<int>> ccs2(n + 1);
  for (int i = 1; i <= n; i++) {
    ccs2[ccs[i]].push_back(i);
  }
  int remct = 0;
  for (int i = 1; i <= n; i++) {
    if (ccs2[i].size() > 1 && ccs2[i].size() % 2) {
      int ect = 0;
      for (int j : ccs2[i]) ect += graph[j].size();
      ect /= 2;
      remct += ect % 2;
    }
  }
  remct += (n - remct) % 2;
  cout << remct;
  return 0;
}
