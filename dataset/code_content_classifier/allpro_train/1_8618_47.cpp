#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> adj[maxn];
int n, m, k;
set<int> st;
void input() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
void init() {
  for (int i = 1; i < n; i++) st.insert(i);
}
void bfs(int r) {
  queue<int> q;
  q.push(r);
  st.erase(r);
  while (q.size()) {
    int v = q.front();
    q.pop();
    vector<int> vec;
    for (auto u : adj[v])
      if (st.find(u) != st.end()) st.erase(u), vec.push_back(u);
    for (auto u : st) q.push(u);
    st.clear();
    for (auto u : vec) st.insert(u);
  }
}
bool valid() {
  int t = 0;
  bool ok[maxn];
  memset(ok, 1, sizeof ok);
  for (auto u : adj[0]) ok[u] = false;
  for (int i = 1; i < n; i++)
    if (st.find(i) != st.end() && ok[i]) bfs(i), t++;
  return t <= k;
}
int main() {
  input();
  init();
  if (adj[0].size() > n - 1 - k || !valid() || st.size())
    cout << "impossible" << endl;
  else
    cout << "possible" << endl;
}
