#include <bits/stdc++.h>
using namespace std;
string p = "qwertyuiop", q = "asdfghjkl;", r = "zxcvbnm,./";
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a + b + c, min(2 * (a + b), min(2 * (b + c), 2 * (a + c))))
       << endl;
  return 0;
}
