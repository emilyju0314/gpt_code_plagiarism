#include <bits/stdc++.h>
using namespace std;
inline int ty() {
  register int a = 0, b = 1, c = getchar();
  while (!isdigit(c)) b ^= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return b ? a : -a;
}
const int _ = 53;
struct node {
  int x, y;
  node(int _x = 0, int _y = 0) { x = _x, y = _y; }
  inline friend int operator<(node a, node b) { return a.x < b.x; }
} p[_];
int n;
const string st = "(((1-abs((t-", md = ")))+abs((1-abs((t-", en = ")))))*";
int main() {
  register int i, a, b;
  n = ty();
  for (i = 1; i <= n; i++) a = ty(), b = ty(), ty(), p[i] = node(a, b);
  sort(p + 1, p + n + 1);
  register string F = "", G = "", x;
  for (i = 1; i < n; i++) F += '(', G += '(';
  for (i = 1; i <= n; i++) {
    x = to_string(i - 1);
    F += st + x + md + x + en + to_string(p[i].x / 2) + ")";
    G += st + x + md + x + en + to_string(p[i].y / 2) + ")";
    if (i > 1) F += ')', G += ')';
    if (i < n) F += '+', G += '+';
  }
  cout << F << endl << G << endl;
  return 0;
}
