#include <bits/stdc++.h>
using namespace std;
string str, cmp, sec;
int main() {
  ios::sync_with_stdio(false);
  int i, j, x, y, n, m;
  cmp = sec = "";
  cin >> n;
  if (n == 24) {
    cin >> str;
    cmp = cmp + str[0];
    cmp = cmp + str[1];
    sec = sec + str[3];
    sec = sec + str[4];
    if (cmp > "23") str[0] = '0';
    if (sec > "59") str[3] = '0';
    cout << str;
  } else {
    cin >> str;
    cmp = cmp + str[0];
    cmp = cmp + str[1];
    sec = sec + str[3];
    sec = sec + str[4];
    if (cmp > "12" && str[1] != '0')
      str[0] = '0';
    else if (cmp > "12")
      str[0] = '1';
    else if (cmp == "00")
      str[0] = '1';
    if (sec > "59") str[3] = '0';
    cout << str;
  }
  return 0;
}
