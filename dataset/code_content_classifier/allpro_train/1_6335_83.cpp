#include <bits/stdc++.h>
using namespace std;
int dfsRec(int n, map<int, vector<int>>& adj, map<int, bool>& visited,
           int depth, bool* cond) {
  int temp = 0;
  visited[n] = true;
  vector<int> values;
  bool ignoreOne = false;
  for (auto it = adj[n].begin(); it != adj[n].end(); it++) {
    if (!visited[*it]) {
      bool condTemp = false;
      int temp2 = dfsRec(*it, adj, visited, depth + 1, &condTemp) + 1;
      *cond = *cond || condTemp;
      if (temp2 == 1) {
        ignoreOne = ignoreOne || !values.empty();
        values.push_back(temp2);
      } else {
        temp += temp2;
      }
    }
  }
  if (depth != 1 && !ignoreOne) {
    for (auto it = values.begin(); it != values.end(); it++) {
      temp += *it;
    }
  } else if (depth != 1 || temp == 0) {
    temp += 1;
  }
  if (temp == 0) {
    *cond = (depth) % 2;
  }
  return temp;
}
int main() {
  int nodes;
  map<int, vector<int>> adj;
  cin >> nodes;
  for (int i = 0; i < nodes; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
  }
  map<int, bool> visited;
  bool cond = false;
  int i = 1;
  while (adj[i].size() != 1) i++;
  int x = dfsRec(i, adj, visited, 0, &cond);
  cout << (cond ? 3 : 1) << ' ' << (x > 2 ? x : 1) << endl;
}
