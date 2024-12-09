#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> a(2 * n);
  ll ans1, ans2;
  for (int i = 0; i < (2 * n); ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ans1 = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  ll min_wid = 1000000010;
  for (int i = 0; i < (n + 1); ++i) {
    min_wid = min(min_wid, a[n - 1 + i] - a[0 + i]);
  }
  ans2 = min_wid * (a[2 * n - 1] - a[0]);
  cout << min(ans1, ans2) << endl;
}
