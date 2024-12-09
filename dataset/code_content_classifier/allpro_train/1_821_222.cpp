#include <bits/stdc++.h>
using namespace std;
long long m = 1002, n, r, s = 0, i, j, p = 1, a[1010][1010];
int main() {
  for (i = 1; i < m; i++)
    for (j = 2, a[i][1] = 1; j <= i; j++)
      (a[i][j] += a[i - 1][j] + a[i - 1][j - 1]) %= 1000000007;
  for (cin >> n, i = 0; i < n; i++)
    cin >> r, s += r, (p *= a[s][r]) %= 1000000007;
  cout << p << endl;
  return 0;
}
