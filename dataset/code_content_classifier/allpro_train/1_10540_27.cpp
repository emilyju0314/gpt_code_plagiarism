#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
float area(float x1, float y1, float x2, float y2, float x3, float y3) {
  return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool check(float x1, float y1, float x2, float y2, float x3, float y3, float x4,
           float y4, float x, float y) {
  float a = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3);
  float a1 = area(x1, y1, x2, y2, x, y);
  float a2 = area(x2, y2, x3, y3, x, y);
  float a3 = area(x3, y3, x4, y4, x, y);
  float a4 = area(x1, y1, x4, y4, x, y);
  if (a == (a1 + a2 + a3 + a4)) return true;
  return false;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int n, m, b, c, d, k, l, r, x, y;
int dp[100007];
int a[100007];
int main() {
  cin >> l >> r >> x >> y;
  long long int s = 0;
  for (long long int i = 1; i * i <= y; i += 1) {
    long long int p = x * y;
    if (y % i == 0) {
      if ((i >= l && i <= r) && ((p >= l * i) && (p <= r * i))) {
        long long int p1 = gcd(i, p / i);
        long long int p2 = p / p1;
        if ((p1 == x) && (p2 == y)) {
          s += 1;
        }
      }
      if (y != (i * i)) {
        if ((y >= l * i && y <= r * i) &&
            ((p * i >= l * y) && (p * i <= r * y))) {
          long long int p1 = gcd(y / i, (p * i) / y);
          long long int p2 = p / p1;
          if ((p1 == x) && (p2 == y)) {
            s += 1;
          }
        }
      }
    } else if (x % i == 0) {
      if ((i >= l && i <= r) && ((p >= l * i) && (p <= r * i))) {
        long long int p1 = gcd(i, p / i);
        long long int p2 = p / p1;
        if ((p1 == x) && (p2 == y)) {
          s += 1;
        }
      }
      if (x != (i * i)) {
        if ((x >= l * i && x <= r * i) &&
            ((p * i >= l * x) && (p * i <= r * x))) {
          long long int p1 = gcd(x / i, (p * i) / x);
          long long int p2 = p / p1;
          if ((p1 == x) && (p2 == y)) {
            s += 1;
          }
        }
      }
    }
  }
  cout << s;
}
