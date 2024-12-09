#include <bits/stdc++.h>
using namespace std;
bool cl(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
void task() {
  int index = 0, k;
  cin >> k;
  for (int i = 0; i < 11000000; ++i) {
    int d = i, s = 0;
    while (d > 0) {
      s += d % 10;
      d /= 10;
    }
    if (s == 10) {
      ++index;
      if (k == index) {
        cout << i;
        break;
      }
    }
  }
}
int main(void) { task(); }
