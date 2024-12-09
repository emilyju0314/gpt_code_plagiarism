#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int seat4 = n, seat2 = n * 2, seat1 = 0;
    int need_seat4, need_seat2;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      while (a > 0) {
        if (seat4 > 0 && a >= 3)
          seat4--, a -= 4;
        else if (seat2 > 0 && a >= 2)
          seat2--, a -= 2;
        else if (a == 1)
          seat1--, a--;
        else if (seat4 > 0)
          seat4--, a -= 2, seat1++;
        else
          seat1--, a--;
      }
    }
    if (seat4 >= 0 && seat4 * 2 + seat2 + seat1 >= 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
