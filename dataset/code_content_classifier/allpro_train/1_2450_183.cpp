#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i, j;
    for (i = 0; i < n; i++) cin >> a[i];
    long long int ans = 0;
    ans += a[0] == 1;
    i = 1;
    while (i < n) {
      if (a[i] == 0) {
        i++;
        continue;
      }
      j = i;
      while (j < n && a[j] == 1) j++;
      ans += (j - i) / 3;
      i = j;
    }
    cout << ans << " ";
    cout << "\n";
  }
}
