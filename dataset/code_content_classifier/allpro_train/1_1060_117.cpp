#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    long long an = 0, s = 1, mx = 0;
    for (auto &i : a) {
      if (s == (i < 0)) {
        an += mx;
        s = 1 - s;
        mx = INT_MIN;
      }
      mx = max(mx, i);
    }
    cout << an + mx << endl;
  }
}
