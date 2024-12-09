#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long cnt = 0;
    set<long long> res;
    for (long long i = 0; i < n; i++) {
      if (a[i] % 2 == 0) res.insert(a[i]);
    }
    if (res.size() == 0)
      cout << 0 << endl;
    else {
      while (res.size() > 0) {
        long long m1 = *res.rbegin();
        res.erase(m1);
        if (m1 % 2 == 0) {
          res.insert(m1 / 2);
          cnt++;
        }
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
