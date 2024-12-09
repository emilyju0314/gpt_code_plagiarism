#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return y < x ? (x = y, 1) : 0;
}
const int maxn = 3e3 + 17;
long long t, a, b;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> t >> a >> b;
  if (t == 1)
    if (a == 1)
      if (b == 1)
        cout << "inf" << '\n';
      else
        cout << 0 << '\n';
    else {
      long long get = 0, cp = b;
      while (cp) get += cp % a, cp /= a;
      while (b != 1)
        if (b % a)
          return cout << (get == a) << '\n', 0;
        else
          b /= a, cp = 1;
      cout << cp + (get == a) << '\n';
    }
  else {
    long long get = 0, cp = b;
    if (a != 1)
      for (long long tp = 1; cp; tp *= t) get += cp % a * tp, cp /= a;
    cout << (a == b) + (a != 1 && get == a) << '\n';
  }
  return 0;
}
