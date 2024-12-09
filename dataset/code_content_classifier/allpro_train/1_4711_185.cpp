#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1 = 0, sum2 = 0, oe = 0, v2, v1;
  cin >> n;
  for (int x = 0; x < n; x++) {
    cin >> v1 >> v2;
    if (((v1 % 2 == 0) && (v2 % 2 == 1)) || ((v2 % 2 == 0) && (v1 % 2 == 1))) {
      oe = 1;
    }
    sum1 += v1;
    sum2 += v2;
  }
  if ((sum1 % 2 == 0) && (sum2 % 2 == 0)) {
    cout << 0;
  } else if (((sum1 % 2 == 0) && (sum2 % 2 == 1)) ||
             ((sum2 % 2 == 0) && (sum1 % 2 == 1))) {
    cout << -1;
  } else {
    if (oe != 1) {
      cout << -1;
    } else {
      cout << 1;
    }
  }
}
