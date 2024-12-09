#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
double pi = acos(-1);
long long fastpower(long long b, long long p) {
  long long ans = 1;
  while (p) {
    if (p % 2) {
      ans = (ans * b);
    }
    b = b * b;
    p /= 2;
  }
  return ans;
}
string makeitstring(long long n) {
  string ans;
  bool ch = 0;
  if (n < 0) {
    n *= -1;
    ch = 1;
  }
  if (n == 0) {
    ans = "0";
  };
  while (n) {
    long long mo = n % 10;
    mo += 48;
    char m = mo;
    ans = m + ans;
    n /= 10;
  }
  if (ch) {
    ans = '-' + ans;
  }
  return ans;
}
bool checksqrt(long long f) {
  long long num = sqrt(f);
  return (num * num == f);
}
bool compare(double f, double s) { return (abs(f - s) < eps); }
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long a2 = a;
    a = b;
    b = a2 % b;
  }
  return a;
}
const int M = 1e9 + 7;
const int sz = 1e2 + 10;
long long add(long long a, long long b, long long m) {
  return (a % m + b % m) % m;
}
long long mul(long long a, long long b, long long m) {
  return (a % m * b % m) % m;
}
long long fastpowermod(long long b, long long p, long long m) {
  long long ans = 1;
  while (p) {
    if (p % 2) {
      ans = mul(ans, b, m);
    }
    b = mul(b, b, m);
    p /= 2;
  }
  return ans % m;
}
long long inv(long long num) { return (fastpowermod(num, M - 2, M)); }
long long NcR(long long n, long long r) {}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long sum, oR;
  cin >> sum >> oR;
  long long And = (sum - oR) / 2;
  if (And * 2 + oR != sum || And < 0 || (And & oR) != 0) {
    cout << 0;
    return 0;
  }
  int cnt = 0;
  while (oR) {
    if (oR % 2) {
      cnt++;
    }
    oR /= 2;
  }
  cout << fastpower(2, cnt) - ((And == 0) ? 2 : 0);
  return 0;
}
