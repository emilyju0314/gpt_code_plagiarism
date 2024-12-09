#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double zero = 1e-8;
const double oo = 1e9 + 1;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct RAT {
  unsigned long long fz, fm;
  void clean() {
    unsigned long long g = gcd(fz, fm);
    fz /= g;
    fm /= g;
  }
  RAT() : fz(0), fm(1) {}
  RAT(unsigned long long a, unsigned long long b) {
    fz = a;
    fm = b;
    clean();
  }
  RAT rev() { return RAT(fm, fz); }
  void writeln() {
    clean();
    cout << fz << '/' << fm << endl;
  }
};
RAT operator+(RAT a, RAT b) {
  RAT ret;
  unsigned long long g = gcd(a.fm, b.fm);
  ret.fm = a.fm / g * b.fm;
  ret.fz = a.fz * (ret.fm / a.fm) + b.fz * (ret.fm / b.fm);
  ret.clean();
  return ret;
}
RAT operator-(RAT a, RAT b) {
  RAT ret;
  unsigned long long g = gcd(a.fm, b.fm);
  ret.fm = a.fm / g * b.fm;
  ret.fz = a.fz * (ret.fm / a.fm) - b.fz * (ret.fm / b.fm);
  ret.clean();
  return ret;
}
RAT operator*(RAT a, RAT b) {
  a.clean();
  b.clean();
  unsigned long long g = gcd(a.fz, b.fm);
  a.fz /= g;
  b.fm /= g;
  g = gcd(a.fm, b.fz);
  a.fm /= g;
  b.fz /= g;
  return RAT(a.fz * b.fz, a.fm * b.fm);
}
int main() {
  unsigned long long n;
  cin >> n;
  if (n == 1) {
    puts("0/1");
    return 0;
  }
  RAT left, right(1, 1);
  unsigned long long m = n, k = 1;
  unsigned long long MI[70];
  MI[0] = 1;
  for (int i = 1; i < 64; ++i) MI[i] = MI[i - 1] * 2;
  while (MI[k] < n) ++k;
  RAT out(1, 1);
  unsigned long long r = k;
  while (m > 0 && r > 0) {
    unsigned long long half = MI[--r];
    left = left + out;
    out = out * RAT(1, 2);
    if (m == half) {
      right = right - out;
      left = left + (out * RAT(r, 1));
      m = 0;
    } else if (m < half) {
      right = right - out;
    } else {
      left = left + (out * RAT(r, 1));
      m -= half;
    }
  }
  RAT ans = left * right.rev();
  ans.writeln();
  return 0;
}
