#include <bits/stdc++.h>
using namespace std;
vector<int> V[300100];
int n, q;
int parent[300100];
int height[300100];
int res[300100];
void DFS(int x) {
  height[x] = 1;
  for (int i = 0; i < V[x].size(); i++) {
    int t = V[x][i];
    if (t != parent[x]) {
      DFS(t);
      height[x] += height[t];
    }
  }
  int child = -1;
  for (int i = 0; i < V[x].size(); i++) {
    int t = V[x][i];
    if (height[t] > height[x] / 2) {
      child = t;
      break;
    }
  }
  if (child == -1) {
    res[x] = x;
    return;
  }
  int tmp = res[child];
  while (1) {
    if (height[tmp] <= height[x] / 2)
      tmp = parent[tmp];
    else
      break;
  }
  res[x] = tmp;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> parent[i];
    V[parent[i]].push_back(i);
  }
  DFS(1);
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    cout << res[x] << endl;
  }
  return 0;
}
