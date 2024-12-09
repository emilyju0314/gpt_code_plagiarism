#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long oo = 1000111000111000111LL;
long long check(long long a, long long b, long long c) {
  if (a > b) swap(a, b);
  long long res = a;
  c += a;
  b -= a;
  a -= a;
  if (b % 2 == 1) return oo;
  if (c == 0) return oo;
  res += b;
  return res;
}
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long res = oo;
  res = min(res, check(a, b, c));
  res = min(res, check(b, c, a));
  res = min(res, check(c, a, b));
  if (res == oo) res = -1;
  cout << res << endl;
  return 0;
}
