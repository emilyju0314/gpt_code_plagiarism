#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], c[10000];
int last[10000];
vector<int> front[10000];
priority_queue<int, vector<int>, greater<int>> q;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    last[i] = i;
  }
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    last[v] = max(last[v], u);
  }
  for (int i = 1; i <= n; i++) {
    front[last[i]].push_back(c[i]);
  }
  int cur = k, ans = 0;
  if (cur < a[1]) {
    cout << "-1";
    return 0;
  }
  for (int i = 1; i <= n + 1; i++) {
    cur += b[i];
    for (auto &cl : front[i]) {
      cur--;
      q.push(cl);
    }
    while (!q.empty() && cur < a[i + 1]) {
      cur++;
      q.pop();
    }
    if (cur < a[i + 1]) {
      cout << "-1";
      return 0;
    }
  }
  while (!q.empty()) ans += q.top(), q.pop();
  cout << ans << endl;
}
