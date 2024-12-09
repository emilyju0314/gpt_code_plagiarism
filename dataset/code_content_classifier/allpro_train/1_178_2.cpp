#include <bits/stdc++.h>
int k;
int n;
int a, b;
int maxla;
int minrb;
using namespace std;
int main() {
  cin >> k;
  while (k--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (i == 0) {
        maxla = a;
        minrb = b;
      } else {
        maxla = max(maxla, a);
        minrb = min(minrb, b);
      }
    }
    int ans = 0;
    if (maxla - minrb > 0) {
      ans = maxla - minrb;
    }
    cout << ans << endl;
  }
  return 0;
}
