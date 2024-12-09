#include <bits/stdc++.h>
#pragma comment(linker, "/stack:640000000")
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);
template <class T>
inline T _abs(T n) {
  return ((n) < 0 ? -(n) : (n));
}
template <class T>
inline T _max(T a, T b) {
  return (!((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _min(T a, T b) {
  return (((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _swap(T& a, T& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i <= n - 1; i++) {
      if (a[i] < 0) {
        sum += abs(a[i]);
        m--;
      }
      if (m == 0) break;
    }
    printf("%d\n", sum);
  }
  return 0;
}
