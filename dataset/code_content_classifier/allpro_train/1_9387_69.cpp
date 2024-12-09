#include <bits/stdc++.h>
using namespace std;
const int maxint = 1000 * 1000 * 1000;
#pragma comment(linker, "/STACK:268435456")
int main() {
  long long n, k, i, e = 0, a, s = 0, t = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (i > 1 && t - (n - i) * a * (i - e - 1) < k) {
      cout << i << endl;
      e++;
    } else
      t += a * (i - 1 - e);
  }
  return 0;
}
