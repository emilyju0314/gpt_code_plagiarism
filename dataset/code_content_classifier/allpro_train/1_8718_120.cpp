#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long n1 = a - c;
  long long n2 = b - c;
  long long n = d - (n1 + n2 + c);
  if (n1 < 0 || n2 < 0 || n <= 0) {
    cout << -1 << endl;
  } else
    cout << n << endl;
}
