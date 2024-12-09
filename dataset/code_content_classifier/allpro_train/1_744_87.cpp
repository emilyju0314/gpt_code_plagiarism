#include <bits/stdc++.h>
using namespace std;
int nod(int a, int b) {
  while (a != 0) {
    int c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  int n;
  cin >> n;
  for (int i = n / 2; i > 0; --i) {
    int a = i;
    int b = n - i;
    int f = nod(a, b);
    if (f == 1) {
      cout << a << ' ' << b;
      return 0;
    }
  }
}
