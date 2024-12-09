#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b, int x, int y, int k, string &s) {
  for (int i = 0; i < k; i++) {
    if (s[i] == 'U')
      b--;
    else if (s[i] == 'D')
      b++;
    else if (s[i] == 'L')
      a++;
    else
      a--;
  }
  bool fail = 0;
  if ((a > 0 && x < 0) || (a < 0 && x > 0)) fail = 1;
  if ((b > 0 && y < 0) || (b < 0 && y > 0)) fail = 1;
  a = abs(a), b = abs(b);
  x = abs(x), y = abs(y);
  if ((a == 0 && x != 0) || (x == 0 && a != 0)) fail = 1;
  if ((b == 0 && y != 0) || (y == 0 && b != 0)) fail = 1;
  if (x != 0 && a % x != 0) fail = 1;
  if (y != 0 && b % y != 0) fail = 1;
  if (!fail && a != 0 && b != 0 && a / x != b / y) fail = 1;
  return !fail;
}
int main() {
  long long a, b;
  cin >> a >> b;
  int x = 0, y = 0;
  string s;
  cin >> s;
  for (int i = 0; i < int((s).size()); i++) {
    if (s[i] == 'U')
      y++;
    else if (s[i] == 'D')
      y--;
    else if (s[i] == 'L')
      x--;
    else
      x++;
    if (a == x && b == y) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  bool ret = 0;
  for (int i = 0; i < int((s).size()); i++) ret |= check(a, b, x, y, i, s);
  if (ret || (a == 0 && b == 0))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
