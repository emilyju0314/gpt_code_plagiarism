#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c, a = 0, b = 0, d = 0, res;
  cin >> n;
  while (n--) {
    cin >> m >> c;
    if (m > c)
      a++;
    else if (c > m)
      b++;
    else if (m == c)
      d++;
  }
  res = max(a, b);
  if (a == b) {
    cout << "Friendship is magic!^^" << endl;
  } else {
    if (res == a)
      cout << "Mishka" << endl;
    else if (res == b)
      cout << "Chris" << endl;
  }
  return 0;
}
