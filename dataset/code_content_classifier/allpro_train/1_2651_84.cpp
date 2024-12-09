#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int i = 0;
  cin >> a >> b;
  if (a == b) {
    cout << 1;
    return 0;
  } else {
    while (1) {
      a = a * 3;
      b = b * 2;
      i++;
      if (a > b) break;
    }
  }
  cout << i;
  return 0;
}
