#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, h;
  cin >> n >> h;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int l = 1, r = h;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    long long int sum = mid;
    for (int i = 0; i < n - 1; i++) {
      sum = sum + min(mid, a[i + 1] - a[i]);
    }
    if (sum < h)
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
