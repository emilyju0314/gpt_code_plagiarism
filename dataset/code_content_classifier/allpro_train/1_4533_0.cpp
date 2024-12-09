#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1005;
const int oo = 1000000000;
const long long Base = 1000000007;
typedef int Tarr[MaxN];
long long x, y, a, b, n, m, xx, yy, r1, r2, r3, r4;
void Ok(int Val) {
  int xx = Val * a, yy = Val * b;
  if (xx % 2 == 0) {
    r1 = max((long long)0, min(n - xx, x - xx / 2));
  } else
    r1 = max((long long)0, min(n - xx, x - xx / 2 - 1));
  if (yy % 2 == 0) {
    r2 = max((long long)0, min(m - yy, y - yy / 2));
  } else
    r2 = max((long long)0, min(m - yy, y - yy / 2 - 1));
  r3 = r1 + xx;
  r4 = r2 + yy;
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  int aa = a, bb = b, tmp;
  do {
    tmp = aa % bb;
    aa = bb;
    bb = tmp;
  } while (bb != 0);
  a /= aa;
  b /= aa;
  Ok(min((n) / a, (m) / b));
  cout << r1 << " " << r2 << " " << r3 << " " << r4;
  return 0;
}
