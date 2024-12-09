#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int main() {
  long long x, y, a, b, l, c = 0;
  cin >> x >> y >> a >> b;
  l = (x * y) / GCD(x, y);
  a--;
  cout << b / l - a / l << endl;
  return 0;
}
