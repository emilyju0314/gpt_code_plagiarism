#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, v1, v2, n, k;
  cin >> n >> l >> v1 >> v2 >> k;
  double s = ceil(n / k);
  double d = (l * v2 * (v1 + v2)) / (v2 * (v1 + v2) + 2 * v1 * v2 * (s - 1));
  cout << fixed << setprecision(10) << d / v2 + (l - d) / v1;
}
