#include <bits/stdc++.h>
unsigned long long gcd(unsigned long long a, unsigned long long b);
using namespace std;
int main() {
  int n, i;
  cin >> n;
  unsigned long long num, m = 0, g = 0, r;
  for (i = 0; i < n; i++) {
    cin >> num;
    m = max(m, num);
    g = gcd(num, g);
  }
  r = m / g - n;
  if (r % 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
