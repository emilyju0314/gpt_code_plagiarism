#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, n1, n2, n3, n4, n5, a, mod = 100000, p;
  cin >> n;
  n1 = n / 10000;
  n2 = n / 1000 % 10;
  n3 = n / 100 % 10;
  n4 = n / 10 % 10;
  n5 = n % 10;
  a = n1 * 10000 + n3 * 1000 + n5 * 100 + n4 * 10 + n2;
  p = a * a % mod * a % mod * a % mod * a % mod;
  n1 = p / 10000;
  n2 = p / 1000 % 10;
  n3 = p / 100 % 10;
  n4 = p / 10 % 10;
  n5 = p % 10;
  cout << n1 << n2 << n3 << n4 << n5;
}
