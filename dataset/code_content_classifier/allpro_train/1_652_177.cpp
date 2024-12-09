#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  vector<long long> V(101, 0);
  long long t, k, d;
  long long i;
  for (i = 0; i < q; i++) {
    cin >> t >> k >> d;
    long long j, cnt = 0;
    for (j = 1; j <= n; j++) {
      if (V[j] < t) cnt++;
    }
    if (cnt < k) {
      cout << -1 << endl;
      continue;
    } else {
      long long sum = 0;
      cnt = 0;
      for (j = 1; j <= n; j++) {
        if (cnt < k && V[j] < t) {
          V[j] = t + d - 1;
          cnt++;
          sum += j;
        }
      }
      cout << sum << endl;
    }
  }
  return 0;
}
