#include <bits/stdc++.h>
using namespace std;
int x[12];
double a, b;
int main() {
  for (int i = 1; i <= 11; i++) cin >> x[i];
  for (int i = 11; i >= 1; i--) {
    a = sqrt(abs(x[i])), b = 5 * x[i] * x[i] * x[i];
    a + b <= 400 ? printf("f(%d) = %.2f\n", x[i], a + b)
                 : printf("f(%d) = MAGNA NIMIS!\n", x[i]);
  }
  return 0;
}
