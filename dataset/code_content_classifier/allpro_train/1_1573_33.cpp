#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
int p[N];
set<int> adj[N];
vector<int> ans;
stringstream ss;
pair<int, int> dfs(int v) {
  pair<int, int> cur = pair<int, int>(0, v);
  for (int w : adj[v]) {
    pair<int, int> nxt = dfs(w);
    nxt.first++;
    cur = max(cur, nxt);
  }
  return cur;
}
void print(int v) {
  ss << v << " ";
  for (int w : adj[v]) print(w);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    adj[p[i]].insert(i);
  }
  int w = dfs(0).second;
  int x = w;
  while (x != -1 && p[x] != -1) {
    while (adj[p[x]].size() > 1) {
      ans.push_back(x);
      int y;
      {
        auto iter = adj[p[x]].begin();
        if (*iter == x) iter++;
        y = *iter;
      }
      adj[p[x]].erase(x);
      p[x] = y;
      adj[p[x]].insert(x);
    }
    x = p[x];
  }
  reverse(begin(ans), end(ans));
  print(0);
  ss << endl << ans.size() << endl;
  for (int y : ans) ss << y << " ";
  cout << ss.str() << endl;
  return 0;
}
