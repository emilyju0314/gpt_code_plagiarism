#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, h;
  cin >> h >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  long long sum = 0, mi = 0, k = h;
  for (int i = 0; i < n; ++i) {
    k += v[i];
    sum -= v[i];
    mi = max(mi, sum);
    if (k <= 0) {
      cout << i + 1;
      return 0;
    }
  }
  if (sum <= 0) return cout << -1, 0;
  long long hro = (h - mi) / sum;
  long long ans = hro * n;
  h -= hro * sum;
  for (int i = 0;; ++i) {
    h += v[i % n];
    ++ans;
    if (h <= 0) {
      cout << ans;
      return 0;
    }
  }
}
