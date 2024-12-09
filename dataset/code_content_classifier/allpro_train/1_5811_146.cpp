#include <bits/stdc++.h>
using namespace std;
float mod = pow(10, -10);
int32_t main() {
  long long T = 1;
  for (long long t = 1; t <= T; t++) {
    long long i, ans = 0, a, b, c, q, j = 0, k = 0, n, g, x = 0, y = 0;
    string s, ss, s1;
    cin >> n;
    long long A[15] = {4,   7,   44,  47,  74,  77,  444,
                       447, 474, 477, 744, 747, 774, 777};
    for (i = 0; i < 14; i++) {
      if (A[i] > n) break;
      if (n % A[i] == 0) {
        ans = 1;
        break;
      }
    }
    if (ans == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
