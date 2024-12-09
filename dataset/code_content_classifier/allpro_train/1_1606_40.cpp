#include <bits/stdc++.h>
using namespace std;
complex<double> p[7];
int main() {
  double px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  complex<double> P(px, py), V(vx, vy);
  V /= abs(V);
  V /= complex<double>(0, 1);
  p[0] = complex<double>(0, b);
  p[1] = complex<double>(-a / 2, 0);
  p[2] = complex<double>(-c / 2, 0);
  p[3] = complex<double>(-c / 2, -d);
  p[4] = complex<double>(c / 2, -d);
  p[5] = complex<double>(c / 2, 0);
  p[6] = complex<double>(a / 2, 0);
  cout << fixed << setprecision(15);
  for (int i = 0; i < 7; i++) {
    complex<double> pi = P + V * p[i];
    cout << pi.real() << ' ' << pi.imag() << endl;
  }
  return 0;
}
