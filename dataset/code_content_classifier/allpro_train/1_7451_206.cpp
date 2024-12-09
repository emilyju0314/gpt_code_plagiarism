#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != c) {
      cout << a << " " << c << endl;
    } else if (b != d) {
      cout << b << " " << d << endl;
    } else if (a != d) {
      cout << a << " " << d << endl;
    } else {
      cout << b << " " << c << endl;
    }
  }
}
