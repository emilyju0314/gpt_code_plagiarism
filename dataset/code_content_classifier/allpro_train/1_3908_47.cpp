#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 1e9 + 7;
int binpow(int a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    int b = binpow(a, n / 2);
    return b * b;
  }
}
long long t, n, x;
int main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> x;
    cout << x * 2 << endl;
  }
}
