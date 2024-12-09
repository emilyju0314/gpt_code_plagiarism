#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, T, i, t, ans = 0;
  cin >> n >> T;
  priority_queue<int> q;
  for (i = 1; i <= n; i++) {
    while (!q.empty() && q.top() >= T - i) q.pop();
    cin >> t;
    if (max(t, i) < T) q.push(t - i);
    if (q.size() > ans) ans = q.size();
  }
  cout << ans << endl;
}
