#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, ans = 1e18;
  cin >> n;
  pair<long long, long long> p[n];
  for (long long i = 0; i < n; i++) cin >> p[i].first, p[i].second = i + 1;
  for (long long i = 0; i < n; i++) {
    ans = min(ans, p[i].first / max(p[i].second - 1, n - p[i].second));
  }
  cout << ans;
  return 0;
}
