#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
int n;
long long c[202][202];
void go(int x) {
  int p = x - 1, q = 0;
  int l = 0;
  vector<int> coeffs;
  cout << x - 1 << "\n";
  for (int i = x; i > 0; i -= 2) {
    coeffs.push_back(c[p][q]);
    coeffs.push_back(0);
    q++;
    p--;
  }
  if (x % 2) coeffs.pop_back();
  reverse(coeffs.begin(), coeffs.end());
  for (int J = (0); J < (coeffs.size()); J++) cout << coeffs[J] << " ";
  cout << "\n";
}
int main() {
  int test, cases = 1;
  cin >> n;
  for (int i = (0); i < (n + 1); i++) c[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) & 1;
    }
  }
  go(n + 1);
  go(n);
  return 0;
}
