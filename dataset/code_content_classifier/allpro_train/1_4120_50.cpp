#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
vector<int> arr(MAXN);
vector<bool> visited(MAXN, false);
map<int, int> fre;
void dfs(int x) {
  visited[x] = true;
  fre[arr[x]]++;
  for (int i = 0; i < graph[x].size(); i++) {
    if (!visited[graph[x][i]]) {
      dfs(graph[x][i]);
    }
  }
}
void hehe() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    graph[l].push_back(r);
    graph[r].push_back(l);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      fre.clear();
      dfs(i);
      int ma = 0, total = 0;
      for (auto itr : fre) {
        total += itr.second;
        ma = max(ma, itr.second);
      }
      ans += total - ma;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    hehe();
  }
  return 0;
}
