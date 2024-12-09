#include <bits/stdc++.h>
using namespace std;
int n;
long long m, k, a[200001], ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  ans = a[n - 1] * k * (m / (k + 1)) + a[n - 2] * (m / (k + 1)) +
        a[n - 1] * (m % (k + 1));
  cout << ans;
  return 0;
}
