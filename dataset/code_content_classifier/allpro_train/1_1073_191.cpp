#include <bits/stdc++.h>
const char IN[] = "test.inp";
const char OUT[] = "test.out";
const long double PI = acos(-1.0);
const long double E = 2.718281828459045L;
using namespace std;
inline void open() {
  freopen(IN, "r", stdin);
  freopen(OUT, "w", stdout);
}
int main() {
  long i, n, x;
  cin >> n;
  long t = 0;
  for (i = 1; i <= n; i++) {
    cin >> x;
    t = t + x;
  }
  if (t % n == 0)
    cout << n;
  else
    cout << n - 1;
}
