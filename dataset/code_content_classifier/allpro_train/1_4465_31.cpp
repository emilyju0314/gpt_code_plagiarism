#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
double PI = 4 * atan(1);
vector<pair<int, int> > adj[100001];
bool bak[100001];
vector<int> bk;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int ans = MOD;
  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    adj[u].push_back(make_pair(v, l));
    adj[v].push_back(make_pair(u, l));
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    bk.push_back(x);
    bak[x] = 1;
  }
  for (int i : bk)
    for (auto j : adj[i]) {
      if (bak[j.first] == 0) ans = min(ans, j.second);
    }
  if (ans == MOD)
    cout << -1;
  else
    cout << ans;
}
