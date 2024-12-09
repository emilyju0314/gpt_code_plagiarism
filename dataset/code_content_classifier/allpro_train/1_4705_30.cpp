#include <bits/stdc++.h>
using namespace std;
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
const int MAX = 1e5 + 5;
const int LIM = 3e5 + 5;
const int MOD = 1e9 + 7;
const long double EPS = 1e-10;
const double PI = acos(-1.0);
template <class T>
inline T square(T value) {
  return value * value;
}
int main() {
  string s;
  cin >> s;
  string orig;
  int act = 0;
  int bar = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s.substr(i, 3) == "WUB") {
      bar++;
      i += 2;
      if (bar == 1) orig += " ";
    } else {
      orig += s[i];
      act++;
      bar = 0;
    }
  }
  int c = 0;
  for (int i = 0; i < orig.length(); i++) {
    if ((orig[i] == ' ' && c == 0) || c == act)
      continue;
    else {
      if (orig[i] != ' ') c++;
      cout << orig[i];
    }
  }
  return 0;
}
