#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long d = (s / c);
    long long g = (d / a);
    long long n = (g * b);
    long long p = (d + n);
    cout << p << endl;
  }
  return 0;
}
