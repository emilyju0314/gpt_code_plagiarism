#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
const double EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const long double PI = 3.1415926535897932384626433832795;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
unsigned int gcd(unsigned int a, unsigned int b) {
  return a ? gcd(b % a, a) : b;
}
int main(int argc, char **argv) {
  int n;
  cin >> n;
  long long s = 0;
  long long x1 = LINF, x2 = -LINF, asdy1 = LINF, y2 = -LINF;
  for (int i = 0; i < (n); ++i) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    s += (c - a) * (d - b);
    x1 = min(x1, a);
    asdy1 = min(asdy1, b);
    x2 = max(x2, c);
    y2 = max(y2, d);
  }
  cout << ((x2 - x1 == y2 - asdy1 && (x2 - x1) * (y2 - asdy1) == s) ? "YES"
                                                                    : "NO");
  return 0;
}
