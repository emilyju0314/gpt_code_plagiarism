#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0, t;
  cin >> t;
  char a, b, c;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    if (a == '+' && b == '+') {
      ++x;
    }
    if (b == '+' && c == '+') {
      x++;
    }
    if (a == '-' && b == '-') {
      --x;
    }
    if (b == '-' && c == '-') {
      x--;
    }
  }
  cout << x << endl;
  return 0;
}
