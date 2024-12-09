#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          int a1 = a + i;
          int b1 = b + j;
          int c1 = c + k;
          ans = min(ans, abs(a1 - b1) + abs(b1 - c1) + abs(c1 - a1));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
