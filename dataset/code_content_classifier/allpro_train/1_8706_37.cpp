#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0;
  char c, r;
  char y[2];
  for (i = 0; i < 2; i++) {
    cin >> y[i];
  }
  c = y[0];
  r = y[1];
  if ((c == 'a' || c == 'h') && (r == '1' || r == '8')) {
    cout << "3" << endl;
  } else if (c == 'a' || c == 'h')
    cout << "5" << endl;
  else if (r == '1' || r == '8')
    cout << "5" << endl;
  else
    cout << "8" << endl;
  return 0;
}
