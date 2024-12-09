#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, p, k, ans1, n1;
  cin >> n >> b >> p;
  ans1 = 0;
  n1 = n;
  while (n != 1) {
    k = n / 2;
    ans1 += k * (2 * b + 1);
    n = k + n % 2;
  }
  cout << ans1 << " " << p * n1 << endl;
  return 0;
}
