#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
const long double EPSILON = 0.000000001;
const long long int mod = 1000000007;
const long long int AM = 2e5 + 5;
const long double pi = 3.14159265358979323846;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
using namespace std;
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) ans *= i;
  return ans;
}
long long int powm(long long int a, long long int b, long long int n) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
long long int pow(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
long long int min(long long int a, long long int b) {
  if (a > b)
    return b;
  else
    return a;
}
bool cmp(long double x, long double y) {
  if (abs(x - y) <= EPSILON) return 1;
  return 0;
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << n / 2 << "\n";
  }
}
