#include <bits/stdc++.h>
using namespace std;
int main(void) {
  srand(time(0));
  cout << fixed << setprecision(7);
  cerr << fixed << setprecision(7);
  int n, rudi;
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> rudi;
  static int s[1 << 20];
  static int was[1 << 20];
  for (int i = 1; i <= n; ++i) cin >> s[i];
  int ans = 0;
  multiset<int> q;
  if (s[rudi] != 0) s[rudi] = 0, ++ans;
  for (int i = 1; i <= n; ++i)
    if (i != rudi) q.insert(s[i]);
  int cur = 1;
  while (!q.empty() && *q.begin() == 0) {
    q.erase(q.begin());
    while (cur < n - 1 && q.find(cur) != q.end()) ++cur;
    q.insert(cur);
    ++ans;
  }
  for (int i = 1; i <= n && !q.empty(); ++i) {
    if (*q.begin() > i) {
      ++ans;
      auto it = q.end();
      --it;
      q.erase(it);
      q.insert(i);
    }
    while (!q.empty() && *q.begin() == i) q.erase(q.begin());
  }
  cout << ans << '\n';
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
