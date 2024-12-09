#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, a[maxn], m;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i], q.push(a[i]);
  for (int i = 1; i <= m; ++i) {
    int u = q.top();
    q.pop();
    u++;
    q.push(u);
  }
  int mx = 0;
  while (!q.empty()) mx = max(mx, q.top()), q.pop();
  cout << mx << " ";
  sort(a + 1, a + 1 + n);
  cout << a[n] + m << endl;
  return 0;
}
