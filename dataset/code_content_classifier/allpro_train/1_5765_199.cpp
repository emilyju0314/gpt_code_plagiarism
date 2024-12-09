#include <bits/stdc++.h>
using namespace std;
long long int extendedEuclid(long long int a, long long int b, long long int* x,
                             long long int* y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = extendedEuclid(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int main() {
  long long int A, B, C, x, y, ebob;
  cin >> A >> B >> C;
  ebob = extendedEuclid(A, B, &x, &y);
  if (C % ebob != 0)
    cout << -1 << endl;
  else {
    cout << -1 * x * C / ebob;
    cout << " ";
    cout << -1 * y * C / ebob;
    cout << endl;
  }
  return 0;
}
