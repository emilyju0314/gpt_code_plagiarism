#include <bits/stdc++.h>
using namespace std;
long long q, n, x, y, dir[10];
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    dir[1] = -100000;
    dir[2] = 100000;
    dir[3] = 100000;
    dir[4] = -100000;
    for (int i = 1; i <= n; i++) {
      cin >> x >> y;
      int t;
      for (int j = 1; j <= 4; j++) {
        cin >> t;
        if (t == 0) {
          if (j == 1) {
            dir[j] = max(dir[j], x);
          } else if (j == 2) {
            dir[j] = min(dir[j], y);
          } else if (j == 3) {
            dir[j] = min(dir[j], x);
          } else if (j == 4) {
            dir[j] = max(dir[j], y);
          }
        }
      }
    }
    if (dir[1] > dir[3] || dir[2] < dir[4])
      cout << 0 << endl;
    else {
      cout << 1 << " " << dir[1] << " " << dir[2] << endl;
    }
  }
}
