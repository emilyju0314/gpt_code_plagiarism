#include <bits/stdc++.h>
using namespace std;
int diso[200010];
int dise[200010];
int ans[200010];
vector<int> edge[200010];
vector<int> odd, even;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    diso[i] = dise[i] = 1e9;
    int a;
    cin >> a;
    if (i + a <= n) {
      edge[i + a].push_back(i);
    }
    if (i - a >= 1) {
      edge[i - a].push_back(i);
    }
    if (a & 1)
      odd.push_back(i);
    else
      even.push_back(i);
  }
  queue<pair<int, int>> q;
  for (int i : odd) {
    diso[i] = 0;
    q.push({i, 0});
  }
  while (!q.empty()) {
    int v = q.front().first;
    int cost = q.front().second;
    q.pop();
    if (diso[v] < cost) continue;
    for (int x : edge[v]) {
      if (diso[x] > diso[v] + 1) {
        diso[x] = diso[v] + 1;
        q.push({x, diso[x]});
      }
    }
  }
  for (int i : even) {
    if (diso[i] == 1e9)
      ans[i] = -1;
    else
      ans[i] = diso[i];
  }
  for (int i : even) {
    dise[i] = 0;
    q.push({i, 0});
  }
  while (!q.empty()) {
    int v = q.front().first;
    int cost = q.front().second;
    q.pop();
    if (dise[v] < cost) continue;
    for (int x : edge[v]) {
      if (dise[x] > dise[v] + 1) {
        dise[x] = dise[v] + 1;
        q.push({x, dise[x]});
      }
    }
  }
  for (int i : odd) {
    if (dise[i] == 1e9)
      ans[i] = -1;
    else
      ans[i] = dise[i];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}
