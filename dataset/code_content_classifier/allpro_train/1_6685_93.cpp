#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int main() {
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long n;
    cin >> n;
    long long x = 4 * n;
    long long k = 0;
    while (x - 4 >= n) {
      cout << 9;
      x -= 4;
      k++;
    }
    while (k < n) {
      cout << 8;
      k++;
    }
    cout << endl;
  }
  return 0;
}
