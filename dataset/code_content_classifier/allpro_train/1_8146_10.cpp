#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
void solve() {
  char op[10];
  int ans = 0, pos = 0;
  for (int i = 0; i <= 30; i++) {
    int x = 1 << i, y = i == 0 ? 0 : 1 << (i - 1);
    cout << "? " << y << " " << x << endl;
    fflush(stdout);
    cin >> op;
    if (op[0] == 'x') {
      pos = i - 1;
      break;
    }
  }
  if (pos != -1) {
    ans = 1 << pos;
    for (int i = pos - 1; ~i; i--) {
      int x = 1 << i;
      cout << "? " << ans << " " << ans + x << endl;
      fflush(stdout);
      scanf("%s", op);
      if (op[0] == 'y') ans += 1 << i;
    }
  }
  cout << "! " << ans + 1 << endl;
}
int main() {
  char p[100];
  while (cin >> p && p[0] != 'e') solve();
  return 0;
}
