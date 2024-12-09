#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, a[1001], y = 0, l = -1;
  cin >> n;
  for (i = 2; i <= n; ++i, y = 0) {
    for (j = 2; j * j <= i; ++j)
      if (i % j == 0) y = 1;
    j = i;
    while (!y && j <= n) {
      a[++l] = j;
      j *= i;
    }
  }
  cout << ++l << endl;
  while (l--) cout << a[l] << " ";
  return 0;
}
