#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int tst, a, b, c, r;
  cin >> tst;
  for (int w = 1; w <= tst; ++w) {
    cin >> a >> b >> c >> r;
    int aux;
    if (b < a) aux = a, a = b, b = aux;
    int xa = c - r, xb = c + r;
    int intersec = 0;
    if (a <= xa and xa <= b and a <= xb and xb <= b) {
      intersec = xb - xa;
    } else if (a <= xa and xa <= b) {
      intersec = b - xa;
    } else if (a <= xb and xb <= b) {
      intersec = xb - a;
    } else if (xa > b and xb > b)
      intersec = 0;
    else if (xa < a and xb < a)
      intersec = 0;
    else
      intersec = b - a;
    cout << b - a - intersec << endl;
  }
  return 0;
}
