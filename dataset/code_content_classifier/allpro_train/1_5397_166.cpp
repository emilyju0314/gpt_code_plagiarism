#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100100], ans;
int arr[100100], cnt[100100];
bool visited[100100];
int n, m;
void dfs(int v) {
  for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
    cnt[*it]++;
    if (cnt[*it] == arr[*it]) {
      cnt[*it]++;
      ans.push_back(*it);
      dfs(*it);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  int x, y;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == arr[i]) {
      visited[i] = true;
      cnt[i]++;
      ans.push_back(i);
      dfs(i);
    }
  }
  cout << ans.size() << '\n';
  vector<int>::iterator it;
  for (it = ans.begin(); it != ans.end(); it++) cout << *it << ' ';
  return 0;
}
