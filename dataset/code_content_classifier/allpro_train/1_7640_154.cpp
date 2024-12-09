#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n, -1);
  long long mx = 0;
  for (long long i = 1; i < n; ++i) {
    cout << "? " << mx + 1 << ' ' << i + 1 << endl;
    long long k1;
    cin >> k1;
    cout << "? " << i + 1 << ' ' << mx + 1 << endl;
    long long k2;
    cin >> k2;
    if (k1 > k2) {
      a[mx] = k1;
      mx = i;
    } else {
      a[i] = k2;
    }
  }
  a[mx] = n;
  cout << "! ";
  for (auto e : a) cout << e << ' ';
  cout << endl;
  return 0;
}
