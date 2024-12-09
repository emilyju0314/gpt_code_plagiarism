#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int ang, n = 3, k = 1, pie = 180;
    cin >> ang;
    while (n <= 998244353) {
      if ((ang * n) % pie == 0 && (ang * n) / pie <= n - 2) break;
      n++;
    }
    cout << n << endl;
  }
  return 0;
}
