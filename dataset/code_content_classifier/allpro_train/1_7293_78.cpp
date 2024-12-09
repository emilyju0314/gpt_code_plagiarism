#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 30000 + 10;
long long inc[Maxn], decc[Maxn], a[Maxn];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    inc[1] = 0, decc[1] = a[1];
    bool f = 0;
    for (long long i = 2; i <= n; i++) {
      decc[i] = min(decc[i - 1], a[i] - inc[i - 1]);
      inc[i] = a[i] - decc[i];
      if (decc[i] < 0) f = 1;
    }
    if (!f) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
