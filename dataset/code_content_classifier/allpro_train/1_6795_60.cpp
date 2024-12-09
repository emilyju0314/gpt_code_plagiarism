#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b;
  cout.setf(ios::fixed);
  cout.precision(12);
  cin >> a >> b;
  if (a - b < 0)
    cout << -1 << endl;
  else if (a == b)
    cout << a << endl;
  else {
    double x = -1;
    double c = a + b;
    double t = c / (b);
    t = floor(t);
    if ((int)t % 2 == 1) --t;
    if (t != 0) x = c / t;
    cout << x << endl;
  }
}
