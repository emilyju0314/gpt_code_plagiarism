#include <bits/stdc++.h>
using namespace std;
void dfs(bool vis2[], vector<int> graph[], int v) {
  if (vis2[v]) return;
  vis2[v] = 1;
  cout << (char)(v + 'a');
  for (int i = 0; i < graph[v].size(); i++) {
    dfs(vis2, graph, graph[v][i]);
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << "YES\n";
      cout << s[0];
      int k = s[0] - 'a';
      for (int i = 0; i < 26; i++)
        if (i != k) cout << (char)(i + 'a');
      cout << "\n";
      continue;
    }
    vector<int> graph[26];
    int deg[26] = {0};
    bool vis[26][26] = {0};
    for (int i = 0; i < s.size() - 1; i++) {
      int u = s[i] - 'a', v = s[i + 1] - 'a';
      if (!(vis[u][v] || vis[v][u])) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        vis[u][v] = 1;
        vis[v][u] = 1;
        deg[u]++;
        deg[v]++;
      }
    }
    bool check = 0;
    int x;
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (deg[i] > 2) {
        check = 1;
        break;
      }
      if (deg[i] == 1) {
        count++;
        x = i;
      }
    }
    if (count != 2) check = 1;
    if (check) {
      cout << "NO\n";
      continue;
    }
    bool vis2[26] = {0};
    cout << "YES \n";
    dfs(vis2, graph, x);
    for (int i = 0; i < 26; i++) {
      if (!vis2[i]) cout << (char)(i + 'a');
    }
    cout << "\n";
  }
  return 0;
}
