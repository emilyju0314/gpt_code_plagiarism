#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)(2e18);
int a[60][60], b[60][60], an, am, bn, bm;
int f(int x, int y) {
  int res = 0;
  for (int i = 0; i < an; ++i)
    for (int j = 0; j < am; ++j)
      if (i + x < bn && i + x >= 0 && j + y < bm && j + y >= 0)
        res += a[i][j] * b[i + x][j + y];
  return res;
}
int main() {
  cin >> an >> am;
  for (int i = 0; i < an; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < am; ++j) a[i][j] = s[j] - '0';
  }
  cin >> bn >> bm;
  for (int i = 0; i < bn; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < bm; ++j) b[i][j] = s[j] - '0';
  }
  int ax = 0, ay = 1;
  int ans = -100000000;
  for (int x = -bn - bn - an; x <= bn + bn + an; ++x) {
    for (int y = -bm - bm - am; y <= bm + bm + am; ++y) {
      int res = f(x, y);
      if (res >= ans) {
        ans = res;
        ax = x;
        ay = y;
      }
    }
  }
  cout << ax << " " << ay << endl;
  return 0;
}
