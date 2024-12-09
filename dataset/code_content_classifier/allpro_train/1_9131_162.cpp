#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const long long p = 1000 * 1000 * 1000 + 7;
long long sum(long long a, long long b) { return (a + b) % p; }
long long mult(long long a, long long b) { return (a * b) % p; }
int main() {
  long long a, b;
  cin >> a >> b;
  long long ans =
      mult(((b * (b - 1)) / 2) % p, sum(a, mult(b, ((a * (a + 1)) / 2) % p)));
  cout << ans << endl;
  return 0;
}
