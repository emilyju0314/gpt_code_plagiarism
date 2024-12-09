#include <bits/stdc++.h>
using namespace std;
double W(double A, double B) { return sqrt(A * A + B * B); }
const double pi = 3.14159265358979323846;
double Speed, X0, Y0, Max, r;
double R, Theta;
void Init() {
  double X, Y;
  cin >> X >> Y >> Speed >> X0 >> Y0 >> Max >> r;
  R = W(X, Y);
  Speed /= R;
  if (Y > 0)
    Theta = acos(X / R);
  else if (Y < 0)
    Theta = pi * 2 - acos(X / R);
  else if (X > 0)
    Theta = 0;
  else if (X < 0)
    Theta = pi;
}
double Cross(double X0, double Y0, double X1, double Y1, double R) {
  double A = (X0 - X1) * (X0 - X1) + (Y0 - Y1) * (Y0 - Y1);
  double B = 2 * ((X0 - X1) * X1 + (Y0 - Y1) * Y1);
  double C = X1 * X1 + Y1 * Y1 - R * R;
  if (fabs(A) > 1e-8) {
    double X = -B / (2 * A);
    if (X >= 0 && X <= 1)
      if (A * X * X + B * X + C < 0) return true;
  }
  return false;
}
double Distance(double X0, double Y0, double X1, double Y1, double R) {
  if (!Cross(X0, Y0, X1, Y1, R)) return W(X0 - X1, Y0 - Y1);
  double D0 = W(X0, Y0), D1 = W(X1, Y1);
  double Alpha = asin(R / D0), Beta = asin(R / D1);
  double T =
      acos((X0 * X1 + Y0 * Y1) / W(X0, Y0) / W(X1, Y1)) + Alpha + Beta - pi;
  return D0 * cos(Alpha) + D1 * cos(Beta) + R * T;
}
bool OK(double T) {
  double X = cos(Theta + T * Speed) * R, Y = sin(Theta + T * Speed) * R;
  return Distance(X, Y, X0, Y0, r) <= Max * T;
}
int main() {
  Init();
  double Left = 0, Right = 1e5;
  for (int Time = 300; Time--;) {
    double Mid = (Left + Right) / 2;
    if (OK(Mid))
      Right = Mid;
    else
      Left = Mid;
  }
  printf("%0.10lf\n", (Left + Right) / 2);
  return 0;
}
