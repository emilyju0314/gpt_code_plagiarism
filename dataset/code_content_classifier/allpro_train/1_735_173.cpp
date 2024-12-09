#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long p = 0;
  if (a < b - c) {
    p = n / a;
  } else {
    if (n >= b) {
      p = (n - b) / (b - c) + 1;
      n = n - p * (b - c);
    }
    p = p + n / a;
  }
  cout << p << endl;
  return 0;
}
