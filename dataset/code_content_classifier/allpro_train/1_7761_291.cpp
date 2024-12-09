#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vlli = vector<long long int>;
using vpii = vector<pair<int, int>>;
int n, ans, x, res;
vpii a;
vvi adj;
vb visit;
void dfs(int u) {
  visit[u] = true;
  adj[ans].push_back(u);
  if (!visit[a[u].second]) dfs(a[u].second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = make_pair(x, i);
  }
  adj.resize(n + 1);
  sort(a.begin() + 1, a.end());
  visit.assign(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= ans; i++) {
    cout << adj[i].size() << " ";
    for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
    cout << '\n';
  }
}
