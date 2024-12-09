#include <bits/stdc++.h>
using namespace std;
unsigned long long int remov(unsigned long long int a) {
  unsigned long long int t = 0, count = 0;
  while (a) {
    if (a % 10) {
      t += (a % 10) * pow(10, count);
      count++;
    }
    a /= 10;
  }
  return t;
}
int main() {
  unsigned long long int a, b, c;
  cin >> a >> b;
  c = a + b;
  if (remov(c) == (remov(a) + remov(b)))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
