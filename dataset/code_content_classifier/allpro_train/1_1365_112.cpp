#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a % b == 0) {
    cout << 0 << "\n";
    return 0;
  }
  long long mod = a % b;
  long long mm = a / b * b;
  long long mmm = (a / b + 1) * b;
  if (abs(a - mm) * d < abs(a - mmm) * c) {
    cout << abs(a - mm) * d << "\n";
  } else {
    cout << abs(a - mmm) * c << "\n";
  }
  return 0;
}
