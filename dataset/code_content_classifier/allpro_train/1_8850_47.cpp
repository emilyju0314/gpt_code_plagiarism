#include <bits/stdc++.h>
using namespace std;
const int MAX = 30;
vector<int> g[MAX];
bool vis[MAX], cycle, possible = true;
vector<int> ans;
int col[MAX];
void dfs(int u) {
  vis[u] = true;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  ans.push_back(u);
}
void dfs1(int u) {
  col[u] = 1;
  for (int v : g[u]) {
    if (col[v] == 2) continue;
    if (!col[v])
      dfs1(v);
    else
      cycle = true;
  }
  col[u] = 2;
}
void addEdge(string a, string b) {
  int l = min((int)a.size(), (int)b.size());
  int i = 0;
  while (i < l && a[i] == b[i]) i++;
  if (i == l) {
    if ((int)a.size() > (int)b.size()) possible = false;
    return;
  }
  g[a[i] - 'a'].push_back(b[i] - 'a');
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> mp[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vector<string> v(k);
    for (auto &y : v) cin >> y;
    mp[x] = v;
  }
  if (n == 1 && k == 1) {
    vector<bool> used(26, false);
    for (char c : mp[0][0]) {
      if (used[c - 'a']) continue;
      cout << c;
      used[c - 'a'] = true;
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i < n - 1) addEdge(mp[i][k - 1], mp[i + 1][0]);
    for (int x = 0; x < k - 1; x++) addEdge(mp[i][x], mp[i][x + 1]);
  }
  for (int i = 0; i < 26; i++) {
    if (!col[i]) dfs1(i);
  }
  if (cycle || !possible) return cout << "IMPOSSIBLE", 0;
  for (int i = 0; i < 26; i++) {
    if ((int)g[i].size() == 0) continue;
    if (!vis[i]) dfs(i);
  }
  reverse(ans.begin(), ans.end());
  for (int x : ans) cout << char('a' + x);
  return 0;
}
