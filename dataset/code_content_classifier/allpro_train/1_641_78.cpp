#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, m;
  cin >> n;
  long long int x;
  std::vector<pair<long long int, long long int>> a(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> x;
    a[i] = make_pair(x, 0);
  }
  cin >> m;
  std::vector<pair<long long int, long long int>> b(m);
  for (long long int i = 0; i < m; ++i) {
    cin >> x;
    b[i] = make_pair(x, 0);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long int cnt = 0;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      if (abs(a[i].first - b[j].first) <= 1 && a[i].second == 0 &&
          b[j].second == 0) {
        cnt++;
        a[i].second = 1;
        b[j].second = 1;
        break;
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
