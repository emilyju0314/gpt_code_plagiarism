#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, k, x;
  cin >> n >> k;
  x = 1;
  while (k--) {
    x *= 10;
  }
  for (i = 1; i <= x; i++) {
    if ((n * i) % x == 0) {
      cout << n * i;
      break;
    }
  }
  return 0;
}
