#include <bits/stdc++.h>
using namespace std;
int a[10000001];
vector<long long> arr;
int main() {
  long long i, j, n, k, q, x, l, m, f;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> j;
    a[j] = 1;
    arr.push_back(j);
  }
  sort(arr.begin(), arr.end());
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> x;
    f = 0;
    for (j = 1; j <= k; j++) {
      for (l = n - 1; l >= 0; l--) {
        if (j * arr[l] < x) break;
        if (j * arr[l] == x) {
          f = 1;
          break;
        }
        for (m = 1; m < j; m++) {
          if (x - arr[l] * m < 0) break;
          if ((x - arr[l] * m) % (j - m) == 0) {
            if (a[(x - arr[l] * m) / (j - m)] == 1) {
              f = 1;
              break;
            }
          }
        }
        if (f) break;
      }
      if (f) break;
    }
    if (f == 0)
      cout << -1 << endl;
    else
      cout << j << endl;
  }
}
