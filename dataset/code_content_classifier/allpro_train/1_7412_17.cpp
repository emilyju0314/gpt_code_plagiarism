#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 8;
int d[N], trv[N];
;
vector<int> a[N];
void dfs(int u, int id) {
  trv[u] = id;
  for (int i = 0; i < a[u].size(); i++)
    if (trv[a[u][i]] != id) {
      d[a[u][i]] = d[u] + 1;
      dfs(a[u][i], id);
    }
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > tmp;
  for (int i = 2; i <= k + 1; i++) {
    tmp.push_back(make_pair(1, i));
    a[1].push_back(i);
    a[i].push_back(1);
  }
  for (int i = k + 2; i <= n; i++) {
    tmp.push_back(make_pair(i - k, i));
    a[i - k].push_back(i);
    a[i].push_back(i - k);
  }
  dfs(1, 1);
  int max_u = 0, u;
  for (int i = 1; i <= n; i++)
    if (d[i] > max_u) {
      max_u = d[i];
      u = i;
    }
  for (int i = 1; i <= n; i++) d[i] = 0;
  dfs(u, 2);
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, d[i]);
  cout << res << endl;
  for (int i = 0; i < tmp.size(); i++)
    cout << tmp[i].first << ' ' << tmp[i].second << endl;
}
