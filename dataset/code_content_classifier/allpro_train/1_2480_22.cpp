#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long m) {
  long long r = 1;
  for (; y; y >>= 1) {
    if (y & 1) r = r * x % m;
    x = x * x % m;
  }
  return r;
}
const long long mod = 1e9 + 7;
int run_test() {
  int x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int a = x1 + x2 - x3;
  int b = y1 + y2 - y3;
  int c = x2 + x3 - x1;
  int d = y2 + y3 - y1;
  int e = x3 + x1 - x2;
  int f = y3 + y1 - y2;
  cout << 3 << "\n";
  cout << a << " " << b << "\n";
  cout << c << " " << d << "\n";
  cout << e << " " << f << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long t;
  t = 1;
  while (t--) {
    run_test();
  }
}
