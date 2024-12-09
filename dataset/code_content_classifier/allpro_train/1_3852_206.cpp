#include <bits/stdc++.h>
using namespace std;
int q[50000], w[50000], e[50000];
int main() {
  int a = 0, b = 0, c = 0, x, n, h, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1) {
      q[a] = i + 1;
      a++;
    }
    if (x == 2) {
      w[b] = i + 1;
      b++;
    }
    if (x == 3) {
      e[c] = i + 1;
      c++;
    }
  }
  if (q[0] == 0 || w[0] == 0 || e[0] == 0) {
    cout << 0;
    return 0;
  }
  h = min(a, b);
  k = min(b, c);
  cout << min(h, k) << endl;
  for (int j = 0; j < n; j++) {
    if (q[j] != 0 && w[j] != 0 && e[j] != 0)
      cout << q[j] << " " << w[j] << " " << e[j] << endl;
    else
      return 0;
  }
  return 0;
}
