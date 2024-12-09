#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, x, i = 0;
  cin >> n >> k;
  while (n > 0) {
    if ((k * i) > n) {
      x = k * i;
      break;
    } else
      i++;
  }
  cout << x;
  return 0;
}
