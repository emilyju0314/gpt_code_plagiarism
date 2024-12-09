#include <bits/stdc++.h>
using namespace std;
int n, nn, f = 2, g = 2;
int main() {
  cin >> n;
  nn = n - 1;
  while (nn != 0) {
    cout << f << " ";
    f += g;
    if (f % n == 0)
      f = n;
    else
      f %= n;
    g++;
    nn--;
  }
}
