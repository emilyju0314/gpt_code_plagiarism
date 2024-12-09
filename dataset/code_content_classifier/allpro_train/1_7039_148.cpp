#include <bits/stdc++.h>
using namespace std;
int main() {
  double x;
  int a = 0, b = 0, c = 0;
  int arr[100000] = {0, 1};
  cin >> x;
  for (int i = 0; i < x; i++) {
    arr[i + 2] = arr[i] + arr[i + 1];
    a = arr[i - 1];
    b = arr[i];
    if (arr[i + 2] == x) break;
  }
  c = (int)x - (a + b);
  if (x == 1) {
    c = 1;
    a = b = 0;
  }
  if (c < 0 || a < 0 || b < 0 || x != a + b + c)
    cout << "I'm too stupid to solve this problem";
  else
    cout << a << " " << b << " " << c;
  return 0;
}
