#include <bits/stdc++.h>
using namespace std;
double get_x(double yy, double a, double b, double c) {
  return -(b * yy + c) / a;
}
double get_y(double xx, double a, double b, double c) {
  return -(a * xx + c) / b;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  double a, b, c;
  cin >> a >> b >> c;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  complex<double> A = {x1, y1};
  complex<double> B = {x2, y2};
  double ans = abs(A.real() - B.real()) + abs(A.imag() - B.imag());
  x1 = get_x(A.imag(), a, b, c);
  x2 = get_x(B.imag(), a, b, c);
  y1 = get_y(A.real(), a, b, c);
  y2 = get_y(B.real(), a, b, c);
  double curr =
      abs(x1 - A.real()) +
      abs((complex<double>){x1, A.imag()} - (complex<double>){x2, B.imag()}) +
      abs(x2 - B.real());
  ans = min(ans, curr);
  curr =
      abs(x1 - A.real()) +
      abs((complex<double>){x1, A.imag()} - (complex<double>){B.real(), y2}) +
      abs(y2 - B.imag());
  ans = min(ans, curr);
  curr =
      abs(y1 - A.imag()) +
      abs((complex<double>){A.real(), y1} - (complex<double>){x2, B.imag()}) +
      abs(x2 - B.real());
  ans = min(ans, curr);
  curr =
      abs(y1 - A.imag()) +
      abs((complex<double>){A.real(), y1} - (complex<double>){B.real(), y2}) +
      abs(y2 - B.imag());
  ans = min(ans, curr);
  cout.precision(10);
  cout << fixed;
  cout << ans;
  return 0;
}
