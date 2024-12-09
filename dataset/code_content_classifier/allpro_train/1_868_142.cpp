#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, d, k;
  cin >> n >> d >> k;
  if (n <= d) {
    cout << "NO\n";
    return 0;
  }
  if (k == 1) {
    if (n > 2) {
      cout << "NO\n";
      return 0;
    } else {
      cout << "YES\n1 2\n";
      return 0;
    }
  }
  vector<int> deg(n + 1, 0), depth(n + 1, 0), parent(n + 1, -1);
  vector<pair<int, int> > vec;
  queue<int> q;
  for (int i = 1; i <= d; i++) {
    vec.push_back({i, i + 1});
    deg[i]++;
    deg[i + 1]++;
    depth[i] = min(i - 1, d - i + 1);
    q.push(i);
  }
  int nodesDone = d + 1;
  while (!q.empty() && nodesDone < n) {
    int node = q.front();
    q.pop();
    if (depth[node] == 0) continue;
    while (deg[node] < k && nodesDone < n) {
      nodesDone++;
      vec.push_back({node, nodesDone});
      q.push(nodesDone);
      depth[nodesDone] = depth[node] - 1;
      deg[node]++;
      deg[nodesDone]++;
    }
  }
  if (nodesDone != n) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto it : vec) {
      cout << it.first << " " << it.second << endl;
    }
  }
  return 0;
}
