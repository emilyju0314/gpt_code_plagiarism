#include <bits/stdc++.h>
using namespace std;
long long c = 1;
long long begin(long long n) {
  long long x = 9;
  long long v = 0;
  while (n > x * c) {
    n -= x * c;
    c++;
    x = x * 10;
  }
  return n;
}
long long number(long long n, long long v) {
  while (v != 0) {
    n = n / 10;
    v--;
  }
  return n % 10;
}
int main() {
  long long n;
  cin >> n;
  n = begin(n);
  long long v = (long long)(n % c);
  if (n % c != 0) {
    v = c - v;
    n += c - n % c;
  }
  n = n / c;
  n = (long long)(powl(10, c - 1) + n - 1);
  cout << number(n, v);
}
