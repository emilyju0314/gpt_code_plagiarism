#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b;
int main() {
  cin >> a >> b;
  while (a > 0 && b > 0) {
    if (a >= 2 * b)
      a %= 2 * b;
    else if (2 * a <= b)
      b %= 2 * a;
    else
      break;
  }
  cout << a << " " << b << endl;
}
