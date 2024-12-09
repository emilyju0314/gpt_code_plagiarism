#include <bits/stdc++.h>
using namespace std;
void solve() {}
long long a[100500];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, l;
  cin >> n >> k >> l;
  for (long long i = 1; i <= n * k; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n * k + 1);
  long long lim = a[1] + l;
  vector<long long> v;
  long long ans = 0;
  long long b = 0;
  for (long long i = n * k; i >= 1; i--) {
    if (a[i] <= lim and (long long) v.size() >= k - 1) {
      for (long long j = 1; j <= k - 1; j++) {
        v.pop_back();
      }
      ans += a[i];
      b++;
    } else {
      v.push_back(a[i]);
    }
  }
  if (b < n) {
    cout << 0 << '\n';
  } else {
    cout << ans << '\n';
  }
}
