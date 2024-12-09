#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, k, t;
  cin >> t;
  for (; t--;) {
    cin >> a >> b >> k;
    if (k % 2 == 0) {
      a *= k / 2;
      b *= k / 2;
    } else {
      a *= ((k / 2) + 1);
      b *= k / 2;
    }
    cout << a - b << "\n";
  }
}
