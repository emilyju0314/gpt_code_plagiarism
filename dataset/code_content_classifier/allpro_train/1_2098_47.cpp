#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k, l;
    cin >> n >> k >> l;
    long long a[n];
    for (long long i = 0; i <= n - 1; i++) cin >> a[i];
    long long cur = 0;
    long long fg = 1;
    long long curt = k + 1, dec = 1;
    for (long long i = 0; i <= n - 1; i++) {
      if (a[i] > l) {
        fg = 0;
        break;
      }
      long long tem = (l - a[i]) + 1;
      if (tem > k)
        curt = k + 1, dec = 1;
      else {
        if (dec == 1) {
          if (tem < curt) curt = tem;
          curt--;
        } else {
          curt++;
          if (curt + a[i] > l) fg = 0;
        }
      }
      if (curt == 0) dec = 0;
    }
    if (fg)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
