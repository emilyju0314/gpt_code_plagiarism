#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long int inf = 1e18 + 1, mod = 1e9 + 7;
void solve() {
  long long int n, m, a, b, c, d, k, x, y, i, j,
      ans = 0, count = 0, mini = inf, maxi = 0, sign = 0, sum = 0, total = 0;
  cin >> n;
  vector<long long int> v(n + 1), temp(n + 1);
  for (i = 1; i < n + 1; i++) {
    cin >> v[i];
    temp[i] = v[i];
  }
  for (i = 1; i < n + 1; i++) {
    count = 1;
    while (v[i] != i) {
      v[i] = v[v[i]];
      count++;
    }
    cout << count << " ";
    for (j = 1; j < n + 1; j++) {
      v[i] = temp[i];
    }
  }
  cout << "\n";
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int32_t main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
