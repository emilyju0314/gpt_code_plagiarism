#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    int m;
    cin >> n >> m;
    long long sum = 0;
    multiset<int, greater<int>> s;
    for (int i = 0, x; i < m; i++) cin >> x, sum += x, s.insert(x);
    if (sum < n)
      cout << -1 << endl;
    else {
      long long ans = 0;
      while (n) {
        auto a = *s.begin();
        s.erase(s.begin());
        if (a <= n)
          n -= a, sum -= a;
        else if (sum - a < n)
          ++ans, s.insert(a / 2), s.insert(a / 2);
        else
          sum -= a;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
