#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, cnt[3009][3009];
long long ans;
vector<int> v[3009];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (int i = 1; i <= n; i++)
    for (auto j : v[i])
      for (auto k : v[j]) cnt[k][i]++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) ans += cnt[i][j] * (cnt[i][j] - 1) / 2;
  cout << ans;
  return 0;
}
