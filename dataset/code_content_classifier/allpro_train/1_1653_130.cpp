#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<int> vis, ans;
set<int> st;
int main() {
  if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
  int n, m;
  scanf("%d %d ", &n, &m);
  adj.assign(n + 1, vector<int>());
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d ", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  st.insert(1);
  while (!st.empty()) {
    int u = *st.begin();
    st.erase(u);
    vis[u] = 1;
    ans.push_back(u);
    for (int i = 0; i < adj[u].size(); i++)
      if (!vis[adj[u][i]]) st.insert(adj[u][i]);
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
