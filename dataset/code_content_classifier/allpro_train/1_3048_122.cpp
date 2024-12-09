#include <bits/stdc++.h>
using namespace std;
vector<int> graph[220001];
int leaves[200011];
int friends[200011];
void findLeaves(int cur) {
  leaves[cur] = 0;
  for (int next : graph[cur]) {
    if (friends[next] == 1) leaves[cur]++;
  }
  for (int next : graph[cur]) {
    if (friends[next] != 1 && leaves[next] == -1) findLeaves(next);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      graph[i].clear();
      leaves[i] = -1;
      friends[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
      friends[a]++;
      friends[b]++;
    }
    if (k == 1) {
      cout << n - 1 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (friends[i] != 1) {
        findLeaves(i);
        break;
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (leaves[i] >= k) q.push(i);
    int num = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (leaves[cur] < k) continue;
      friends[cur] -= (leaves[cur] / k) * k;
      num += leaves[cur] / k;
      leaves[cur] %= k;
      if (leaves[cur] == 0 && 1 == friends[cur]) {
        leaves[cur] = -1;
        int cnt = 0;
        for (int next : graph[cur]) {
          if (leaves[next] == -1) continue;
          leaves[next]++;
          cnt++;
          if (leaves[next] >= k) q.push(next);
        }
        if (cnt != 1) {
          int b = 1 / 0;
        }
      }
    }
    cout << num << '\n';
  }
}
