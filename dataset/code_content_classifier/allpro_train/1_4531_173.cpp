#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double Max = -1, x, y, temp, angle[100004], diff;
  cin >> n;
  if (n == 1)
    cout << 0.000000000 << endl;
  else {
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      angle[i] = (atan2(y, x)) * 180 / 3.14159265359;
    }
    sort(angle, angle + n);
    Max = INT_MAX * 1.0;
    for (int i = n - 1; i > 0; i--) {
      Max = min(Max, 360 - fabs(angle[i] - angle[i - 1]));
    }
    Max = min(Max, fabs(angle[n - 1] - angle[0]));
    printf("%.10f\n", Max);
  }
  return 0;
}
