#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int v, e;
  cin >> v >> e;
  bool root[v];
  int list[v];
  bool imp[v];
  int wish[v];
  bool used[v];
  for (int i = 0; i < v; i++) {
    root[i] = true;
    used[i] = false;
    imp[i] = false;
  }
  vector<int> adj[v];
  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    f--, s--;
    adj[f].push_back(s);
    root[s] = false;
  }
  int impimpimp = 0;
  for (int i = 0; i < v; i++) {
    cin >> wish[i];
    wish[i]--;
    if (!imp[wish[i]]) {
      impimpimp++;
    }
    imp[wish[i]] = true;
  }
  queue<int> q;
  int curr = 0;
  for (int i = 0; i < v; i++) {
    if (root[i]) {
      q.push(i);
      used[i] = true;
      while (!q.empty()) {
        int fr = q.front();
        q.pop();
        if (imp[fr]) {
          list[curr] = fr;
          curr++;
        }
        for (int j = 0; j < adj[fr].size(); j++) {
          int next = adj[fr][j];
          if (!used[next]) {
            q.push(next);
            used[next] = true;
          }
        }
      }
    }
  }
  if (curr != impimpimp) {
    cout << -1;
    return 0;
  }
  reverse(list, list + curr);
  for (int i = 0; i < v; i++) {
    used[i] = false;
  }
  for (int i = 0; i < curr; i++) {
    q.push(list[i]);
    used[list[i]] = true;
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      if (wish[fr] != list[i]) {
        cout << -1 << '\n';
        return 0;
      }
      for (int j = 0; j < adj[fr].size(); j++) {
        int next = adj[fr][j];
        if (!used[next]) {
          q.push(next);
          used[next] = true;
        }
      }
    }
  }
  cout << curr << '\n';
  for (int i = 0; i < curr; i++) {
    cout << list[i] + 1 << '\n';
  }
  return 0;
}
