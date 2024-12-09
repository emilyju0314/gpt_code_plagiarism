#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, i, d, epe, opo, epo, ope;
  string a;
  cin >> t;
  while (t--) {
    epe = 0;
    opo = 0;
    epo = 0;
    ope = 0;
    cin >> n;
    cin >> a;
    for (i = 0; i < n; i++) {
      d = a[i] - 48;
      if (i % 2 == 0 && d % 2 != 0)
        opo++;
      else if (i % 2 != 0 && d % 2 == 0)
        epe++;
      if (n % 2 == 0 && epe > 0)
        break;
      else if (n % 2 != 0 && opo > 0)
        break;
    }
    if (n % 2 == 0 && epe > 0)
      cout << 2 << endl;
    else if (n % 2 == 0 && epe == 0)
      cout << 1 << endl;
    else if (n % 2 != 0 && opo > 0)
      cout << 1 << endl;
    else if (n % 2 != 0 && opo == 0)
      cout << 2 << endl;
  }
  return 0;
}
