#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  int r1, r2, c1, c2, d1, d2, a1, a2, a3, a4;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++) {
      a1 = i;
      a2 = j;
      if (a1 + a2 == r1) {
        a3 = c1 - a1;
        a4 = c2 - a2;
        if (a1 + a4 == d1 && a2 + a3 == d2 && a3 + a4 == r2) {
          if (a1 > 9 || a2 > 9 || a3 > 9 || a4 > 9 || a1 < 1 || a2 < 1 ||
              a3 < 1 || a4 < 1)
            continue;
          s.insert(a1);
          s.insert(a2);
          s.insert(a3);
          s.insert(a4);
          if (s.size() == 4) {
            cout << a1 << " " << a2 << endl << a3 << " " << a4;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
  return 0;
}
