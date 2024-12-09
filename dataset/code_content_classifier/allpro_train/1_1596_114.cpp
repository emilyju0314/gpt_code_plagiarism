#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a, b;
int path(int x, int y) {
  if ((i - x) % a == 0 && (j - y) % b == 0 &&
      ((i - x) / a - (j - y) / b) % 2 == 0)
    return max(abs((i - x) / a), abs((j - y) / b));
  return 1e9;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> i >> j >> a >> b;
  int z = min(path(1, 1), min(path(1, m), min(path(n, 1), path(n, m))));
  if (z == 1e9 || (z > 0 && (n <= a || m <= b))) {
    cout << "Poor Inna and pony!";
  } else
    cout << z;
  return 0;
}
