#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i, c[n], r;
  for (i = 0; i < n; i++) cin >> c[i];
  for (i = 0; i < n; i++) {
    r = c[i] / 7;
    if (i != n - 1)
      cout << r + 1 << "\n";
    else
      cout << r + 1;
  }
  return 0;
}
