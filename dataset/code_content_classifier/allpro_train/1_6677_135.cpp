#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, point = 0, StepNum = 0;
  cin >> x;
  for (StepNum = sqrt(abs(x)); StepNum < 2 * abs(x); StepNum++) {
    point = (1 + StepNum) * StepNum / 2;
    if (point == abs(x))
      break;
    else if (point > abs(x) && (point - abs(x)) % 2 == 0) {
      break;
    }
  }
  cout << StepNum << endl;
  return 0;
}
