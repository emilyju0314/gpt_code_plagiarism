#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  a = a + c;
  b = b + c;
  if (a == b) {
    cout << a * 2;
  } else if (a > b) {
    cout << b * 2 + 1;
  } else {
    cout << a * 2 + 1;
  }
  return 0;
}
