#include <bits/stdc++.h>
using namespace std;
const long double N = 1e5 + 9;
long double vp, vd, t, f, c, k;
int main() {
  cin >> vp >> vd >> t >> f >> c;
  while ((c - vp * t) * vd / vp > c) {
    k++;
    t = t + vp * t / (vd - vp) * 2 + f;
  }
  cout << k << endl;
}
