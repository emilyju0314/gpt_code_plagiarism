#include <bits/stdc++.h>
using namespace std;
int main() {
  short int i = 0, s = 0, n, x;
  cin >> n >> x;
  x--;
  short int t[n];
  for (i = 0; i < n; i++) cin >> t[i];
  if (t[x] == 1) s++;
  i = 1;
  short int plu = 0, minu = 0;
  while (x + i < n || x - i >= 0) {
    short int c = 0;
    plu = 0;
    minu = 0;
    if (x + i < n) {
      c += t[x + i];
      plu = 1;
    }
    if (x - i >= 0) {
      c += t[x - i];
      minu = 1;
    }
    i++;
    if (plu == 1 && minu == 1 && c == 2)
      s += c;
    else if ((minu == 0 || plu == 0) && c == 1)
      s++;
  }
  cout << s;
  return 0;
}
