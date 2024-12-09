#include <bits/stdc++.h>
using namespace std;
int n, tt;
string s;
int main() {
  cin >> s;
  n = (int)s.size();
  if (s.size() == 1) {
    int x = s[0] - '0';
    if (x % 4 == 0) {
      cout << 4 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    int x = s[n - 1] - '0';
    int y = s[n - 2] - '0';
    y *= 10;
    y += x;
    if (y % 4 == 0) {
      cout << 4 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
