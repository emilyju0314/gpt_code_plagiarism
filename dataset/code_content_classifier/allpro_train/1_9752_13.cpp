#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long n, a;
long long mu(long long x, long long k) {
  if (k == 0) return 1;
  if (k & 1) return mu(x, k - 1) * x % 1000000007;
  long long t = mu(x, k >> 1);
  return t * t % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 2;
  cin >> n;
  bool have_even = false, lonhon1 = false;
  for (int i = 0; i < (n); ++i) {
    cin >> a;
    if (a % 2 == 0) have_even = true;
    if (a > 1) lonhon1 = true;
    T = mu(T, a);
  }
  long long B = T;
  T = T * mu(2, 1000000007 - 2) % 1000000007;
  long long A = (T + 1) % 1000000007;
  if (!have_even) A = (T + 1000000007 - 1) % 1000000007;
  A = A * mu(3, 1000000007 - 2) % 1000000007;
  B = B * mu(2, 1000000007 - 2) % 1000000007;
  cout << A << "/" << B << endl;
  return 0;
}
