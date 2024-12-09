#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, x1;
  cin >> a >> b >> c;
  double y, y1, y2;
  if (a == 0 && b == 0 && c == 0)
    cout << "-1";
  else if (a == 0) {
    if (b != 0) {
      cout << "1"
           << "\n";
      double y = ((double)(-c)) / b;
      cout << fixed << showpoint;
      cout << setprecision(10);
      cout << y << "\n";
    }
    if (b == 0)
      cout << "0"
           << "\n";
  } else {
    x1 = b * b - 4 * a * c;
    if (x1 < 0) {
      cout << "0"
           << "\n";
    }
    if (x1 == 0) {
      cout << "1"
           << "\n";
      y = ((double)-b) / (2 * a);
      cout << fixed << showpoint;
      cout << setprecision(10);
      cout << y << "\n";
    }
    if (x1 > 0) {
      cout << "2"
           << "\n";
      y1 = (double)(-b + sqrt(x1)) / (2 * a);
      cout << fixed << showpoint;
      cout << setprecision(10);
      y2 = (double)(-b - sqrt(x1)) / (2 * a);
      if (a > 0) {
        cout << fixed << showpoint;
        cout << setprecision(10);
        cout << y2 << "\n";
        cout << fixed << showpoint;
        cout << setprecision(10);
        cout << y1 << "\n";
      }
      if (a < 0) {
        cout << fixed << showpoint;
        cout << setprecision(10);
        cout << y1 << "\n";
        cout << fixed << showpoint;
        cout << setprecision(10);
        cout << y2 << "\n";
      }
    }
  }
}
