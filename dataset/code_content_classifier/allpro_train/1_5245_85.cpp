#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  int x1 = 0, y1 = 0, z1 = 0;
  int our = 0;
  long long a = 1, b = 1, c = 1;
  long long res = 1;
  for (int i = (0); i < (((k < x + y + z - 3) ? (k) : (x + y + z - 3))); ++i) {
    if (our == 0) {
      if (x > x1 + 1) {
        x1++;
        res += b * c;
        a++;
      } else
        i--;
    } else if (our == 1) {
      if (y > y1 + 1) {
        res += c * a;
        b++;
        y1++;
      } else
        i--;
    } else if (our == 2) {
      if (z > z1 + 1) {
        res += a * b;
        c++;
        z1++;
      } else
        i--;
    }
    our++;
    if (our == 3) our = 0;
  }
  cout << res << endl;
}
