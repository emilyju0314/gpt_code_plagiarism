#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  cin >> n;
  if (n != 0) {
    do {
      k += a[n % 16];
      n /= 16;
    } while (n != 0);
    cout << k << '\n';
  } else {
    cout << 1 << '\n';
  }
  return 0;
}
