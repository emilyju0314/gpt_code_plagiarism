#include <bits/stdc++.h>
using namespace std;
int main() {
  long long cases, n, g, b;
  cin >> cases;
  while (cases--) {
    cin >> n >> g >> b;
    long long m = (n + 1) / 2;
    long long k = (m + g - 1) / g;
    long long d = m + (k - 1) * b;
    cout << max(n, d) << endl;
  }
  return 0;
}
