#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> s;
vector<int> c;
vector<vector<int>> E;
void dfs(int cur, int p) {
  set<int> used;
  for (int i = 0; i < (s[cur].size()); ++i) {
    int to = s[cur][i];
    if (c[to] != -1) used.insert(c[to]);
  }
  int last = 0;
  for (int i = 0; i < (s[cur].size()); ++i) {
    int to = s[cur][i];
    if (c[to] != -1) continue;
    while (used.count(last)) last++;
    c[to] = last;
    last++;
  }
  for (int i = 0; i < (E[cur].size()); ++i) {
    int to = E[cur][i];
    if (to == p) continue;
    dfs(to, cur);
  }
}
int main() {
  cin >> n >> m;
  s.resize(n);
  for (int i = 0; i < (n); ++i) {
    int t;
    scanf("%d", &t);
    s[i].resize(t);
    for (int j = 0; j < (t); ++j) {
      int cc;
      scanf("%d", &cc);
      cc--;
      s[i][j] = cc;
    }
  }
  E.resize(n);
  for (int i = 0; i < (n - 1); ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  c.resize(m, -1);
  dfs(0, -1);
  for (int i = 0; i < (m); ++i) {
    if (c[i] == -1) c[i] = 0;
  }
  int ans = 0;
  for (int i = 0; i < (c.size()); ++i) {
    c[i]++;
    ans = max(ans, c[i]);
  }
  cout << ans << endl;
  for (int i = 0; i < (c.size()); ++i) {
    if (i != 0) printf(" ");
    printf("%d", c[i]);
  }
  cout << endl;
  return 0;
}
