#include <bits/stdc++.h>
using namespace std;
const int N = 1000007, inf = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / (gcd(a, b)) * b); }
int main() {
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "YES" << endl;
    return 0;
  }
  long long i;
  long long aux = 1;
  for (i = 1; aux <= 1000000000000000000 and i <= k; ++i) {
    aux = lcm(aux, i);
  }
  if (aux >= 0 and aux <= 1000000000000000000 and (n + 1) % aux == 0) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}
