#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t = 1;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(k);
    long long int type, rem = 1e18;
    for (long long int i = 0; i < k; ++i) {
      cin >> a[i];
      long long int r = n % a[i];
      if (rem > r) {
        rem = r;
        type = i + 1;
      }
    }
    cout << type << " " << (n / a[type - 1]);
  }
}
