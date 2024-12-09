#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  a--, b--;
  int ns = 3;
  if (a / m == b / m) {
    cout << 1;
    return 0;
  }
  if (a / m + 1 == b / m || b % m + 1 == a % m || b % m == m - 1 ||
      b == n - 1 || a % m == 0)
    ns = 2;
  if ((a % m == 0 && b % m == m - 1) || (a % m == 0 && b + 1 == n)) ns = 1;
  cout << ns << endl;
  return 0;
}
