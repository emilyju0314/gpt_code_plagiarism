#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
char scn[N][2];
int l, x, mem;
string s;
int main() {
  l = 1;
  x = 25;
  cin >> s;
  for (int i = 1; i <= 10000; i++) {
    scn[i][1] = '.';
  }
  mem = 0;
  l = 1;
  for (int i = 0; i < s.size(); i++) {
    while (mem != s[i]) {
      l++;
      scn[l][1] = 'X';
      l++;
      mem--;
      if (mem < 0) {
        mem = 256 + mem;
      }
    }
    scn[l][1] = 'X';
    l++;
  }
  for (int i = 1; i <= l; i++) {
    cout << scn[i][1] << "." << '\n';
  }
  return 0;
}
