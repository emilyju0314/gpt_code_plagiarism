#include <bits/stdc++.h>
using namespace std;
int a[100005];
int val[100005];
vector<int> v[100005], adj[100005];
map<pair<int, int>, int> maps, check;
int abb = 1;
int flag = 0;
int visit[100005];
int bfs(int x) {
  queue<int> q;
  q.push(x);
  visit[x] = 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    int i = x;
    for (int j = 0; j < adj[i].size(); j++) {
      if (!visit[adj[i][j]] && maps[make_pair(i, adj[i][j])] == 0) {
        q.push(adj[i][j]);
        visit[adj[i][j]] = 1;
        val[adj[i][j]] = (val[i] + 1) % 2;
      } else if (visit[adj[i][j]] && maps[make_pair(i, adj[i][j])] == 0 &&
                 val[i] == val[adj[i][j]]) {
        abb = 0;
        break;
      } else if (!visit[adj[i][j]]) {
        q.push(adj[i][j]);
        visit[adj[i][j]] = 1;
        val[adj[i][j]] = (val[i]);
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      v[y].push_back(i);
    }
  }
  abb = 1;
  for (int i = 1; i <= n; i++) {
    if (check[make_pair(v[i][0], v[i][1])] ||
        check[make_pair(v[i][1], v[i][0])]) {
      if (a[i] == maps[make_pair(v[i][0], v[i][1])])
        continue;
      else {
        abb = 0;
        break;
      }
    } else
      check[make_pair(v[i][0], v[i][1])] = 1;
    adj[v[i][0]].push_back(v[i][1]);
    adj[v[i][1]].push_back(v[i][0]);
    maps[make_pair(v[i][0], v[i][1])] = a[i];
    maps[make_pair(v[i][1], v[i][0])] = a[i];
  }
  for (int i = 1; i <= m && abb; i++) {
    if (visit[i] || adj[i].size() == 0) continue;
    bfs(i);
  }
  string ans = "YES";
  if (!abb) ans = "NO";
  for (int i = 1; i <= n && abb; i++) {
    x = v[i][0];
    y = v[i][1];
    if (a[i] == 0 && val[v[i][0]] == val[v[i][1]]) {
      ans = "NO";
      break;
    }
    if (a[i] == 1 && val[v[i][0]] != val[v[i][1]]) {
      ans = "NO";
      break;
    }
  }
  cout << ans;
  return 0;
}
