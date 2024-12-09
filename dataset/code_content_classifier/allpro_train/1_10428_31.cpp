#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(10005);
bool visited[10005];
int color[10005];
int counter;
void dfs(int node, int prevcolor) {
  visited[node] = true;
  if (prevcolor != color[node]) counter++;
  for (int i = 0; i < adj[node].size(); ++i) {
    if (!visited[adj[node][i]]) {
      dfs(adj[node][i], color[node]);
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int suffix[n];
    memset(suffix, 0, sizeof(suffix));
    if (arr[n - 1] == 0) suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      suffix[i] = suffix[i + 1];
      if (arr[i] == 0) suffix[i]++;
    }
    long long int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (arr[i] == 1) {
        ans += suffix[i + 1];
      }
    }
    cout << ans;
  }
  return 0;
}
