#include <bits/stdc++.h>
using namespace std;
int main() {
  double ans, B, H;
  cin >> ans;
  double ff = 999999999.9;
  for (double h = 1; h <= 10; h++) {
    for (double b = 1; b <= 10; b++) {
      double sum = h * b / sqrt(4 * h * h + b * b);
      double d = fabs(ans - sum);
      if (d < ff) {
        ff = d;
        B = b;
        H = h;
      }
    }
  }
  cout << B << " " << H << endl;
}
