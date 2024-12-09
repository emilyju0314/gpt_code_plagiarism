#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, x, y, flag = 0;
  cin >> p >> x >> y;
  for (int i = y;; i++) {
    if (i % 50 != x % 50) continue;
    int j = (i / 50) % 475, k = 25;
    while (k--) {
      j = (j * 96 + 42) % 475;
      if (j + 26 == p) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << (max(0, i - x) + 50) / 100;
      break;
    }
  }
  return 0;
}
