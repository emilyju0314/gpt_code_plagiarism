#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b, cnt = 0;
  cin >> x >> y >> a >> b;
  for (int i = a; i <= x; i++) {
    for (int j = b; j <= y; j++) {
      if (i > j) cnt++;
    }
  }
  cout << cnt << endl;
  if (cnt > 0) {
    for (int i = a; i <= x; i++) {
      for (int j = b; j <= y; j++) {
        if (i > j) cout << i << " " << j << endl;
      }
    }
  }
  return 0;
}
