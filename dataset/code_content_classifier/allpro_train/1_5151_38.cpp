#include <bits/stdc++.h>
using namespace std;
int v[4010], d[4010], p[4010];
bool dead[4010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> ans;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> v[i] >> d[i] >> p[i];
  for (int i = 1; i <= n; ++i) {
    if (not dead[i])
      ans.push_back(i);
    else
      continue;
    queue<int> die;
    for (int j = i + 1, tmp = v[i]; tmp and j <= n; ++j) {
      if (not dead[j]) {
        p[j] -= tmp--;
        if (p[j] < 0) {
          dead[j] = 1;
          die.push(j);
        }
      }
    }
    while (not die.empty()) {
      int u = die.front();
      die.pop();
      for (int k = u + 1; k <= n; ++k) {
        if (not dead[k]) {
          p[k] -= d[u];
          if (p[k] < 0) {
            dead[k] = 1;
            die.push(k);
          }
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) cout << it << " ";
  cout << endl;
  return 0;
}
