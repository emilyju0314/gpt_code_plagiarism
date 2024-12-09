#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, m, h0 = -1, m0 = 0, c = 1, c0 = 1;
  cin >> n;
  while (n--) {
    cin >> h >> m;
    if (h == h0 && m == m0)
      c++;
    else
      c = 1;
    if (c > c0) c0 = c;
    h0 = h;
    m0 = m;
  }
  cout << c0;
}
