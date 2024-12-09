#include <bits/stdc++.h>
using namespace std;
int n, m, d, res;
pair<int, int> second[200005];
int f[200005];
int mp[200005];
int result[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> d;
  int y;
  for (int i = 1; i <= n; i++) {
    cin >> y;
    second[i] = {y, i};
  }
  sort(second + 1, second + n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = -1;
  }
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (second[j].first - second[i].first <= d && j <= n) j++;
    if (j == n + 1) break;
    f[j++] = i;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == -1) {
      res++;
      mp[i] = res;
    } else {
      mp[i] = mp[f[i]];
    }
  }
  for (int i = 1; i <= n; i++) {
    result[second[i].second] = mp[i];
  }
  cout << res << endl;
  for (int i = 1; i <= n; i++) {
    cout << result[i] << " ";
  }
  return 0;
}
