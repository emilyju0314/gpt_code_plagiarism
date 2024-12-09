#include <bits/stdc++.h>
using namespace std;
long long _set(long long N, long long pos) { return N = N | (1 << pos); }
long long _reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool _check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
bool _upper(char a) { return a >= 'A' && a <= 'Z'; }
bool _lower(char a) { return a >= 'a' && a <= 'z'; }
bool _digit(char a) { return a >= '0' && a <= '9'; }
long long dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
long long dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
long long M[10][10];
bool check(long long x1, long long x2, long long x3, long long x4, long long y1,
           long long y2, long long y3, long long y4) {
  if (x4 > 8 || x4 < 1) return false;
  if (y4 > 8 || y4 < 1) return false;
  if (x3 == x4 && y3 == y4) return false;
  if (y1 != y4 && x1 == x4 &&
      (x3 != x1 || (y3 < y1 && y3 < y4) || (y3 > y1 && y3 > y4)))
    return false;
  if (x1 != x4 && y1 == y4 &&
      (y3 != y1 || (x3 < x1 && x3 < x4) || (x3 > x1 && x3 > x4)))
    return false;
  if (y2 != y4 && x2 == x4 &&
      (x3 != x2 || (y3 < y2 && y3 < y4) || (y3 > y2 && y3 > y4)))
    return false;
  if (x2 != x4 && y2 == y4 &&
      (y3 != y2 || (x3 < x2 && x3 < x4) || (x3 > x2 && x3 > x4)))
    return false;
  for (long long i = 0; i < 8; i++) {
    long long xx = x3 + dx[i], yy = y3 + dy[i];
    if (x4 == xx && y4 == yy) return false;
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  long long x1 = (long long)(s[0] - 'a') + 1, y1 = (long long)(s[1] - '0');
  M[x1][y1] = 1;
  cin >> s;
  long long x2 = (long long)(s[0] - 'a') + 1, y2 = (long long)(s[1] - '0');
  M[x2][y2] = 1;
  cin >> s;
  long long x3 = (long long)(s[0] - 'a') + 1, y3 = (long long)(s[1] - '0');
  M[x3][y3] = 2;
  cin >> s;
  long long x4 = (long long)(s[0] - 'a') + 1, y4 = (long long)(s[1] - '0');
  M[x4][y4] = 3;
  bool f = check(x1, x2, x3, x4, y1, y2, y3, y4);
  if (f) return cout << "OTHER\n", 0;
  for (long long i = 0; i < 8; i++) {
    if (check(x1, x2, x3, x4 + dx[i], y1, y2, y3, y4 + dy[i]))
      return cout << "OTHER\n", 0;
  }
  cout << "CHECKMATE\n";
  return 0;
}
