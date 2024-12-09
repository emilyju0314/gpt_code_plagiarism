#include <bits/stdc++.h>
using namespace std;
void f(int k, int n, int &x, int &y) {
  int c;
  int a;
  if (k == 0) {
    x = y = 0;
    return;
  }
  c = 0;
  for (int i = 0; i < k - 1; ++i) c = 4 * c + 3;
  a = (1 << (k - 1)) - 1;
  if (n <= c) {
    f(k - 1, n, x, y);
    swap(x, y);
  } else if (n <= c + 1 + c) {
    f(k - 1, n - c - 1, x, y);
    y += a + 1;
  } else if (n <= c + 1 + c + 1 + c) {
    f(k - 1, n - c - 1 - c - 1, x, y);
    x += a + 1;
    y += a + 1;
  } else {
    f(k - 1, n - c - 1 - c - 1 - c - 1, x, y);
    x = a - x;
    y = a - y;
    swap(x, y);
    x += a + 1;
  }
}
int main() {
  int a, b;
  int x, y;
  cin >> a >> b;
  f(a, b, x, y);
  cout << x << " " << y;
  return 0;
}
