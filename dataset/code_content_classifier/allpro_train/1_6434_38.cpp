#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
const long long INF = 1e8;
const long double EPS = 1e-7;
const long double PI = 3.14159265358979323;
long long cross_product(long long x1, long long y1, long long x2,
                        long long y2) {
  return x1 * y2 - y1 * x2;
}
signed main() {
  long long xa, xb, xc, ya, yb, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  long long p = cross_product(xc - xa, yc - ya, xb - xa, yb - ya);
  if (!p) {
    cout << "TOWARDS\n";
  } else if (p > 0) {
    cout << "RIGHT\n";
  } else {
    cout << "LEFT\n";
  }
  return 0;
}
