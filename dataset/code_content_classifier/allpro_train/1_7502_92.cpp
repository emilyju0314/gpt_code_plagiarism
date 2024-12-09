#include <bits/stdc++.h>
using namespace std;
const long double E = 2.71828182845904523536;
const long double pi = acos(-1);
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long inf = 1LL << 30;
const int N = 100100;
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  y--;
  if (y == -1) {
    printf("No");
    return 0;
  }
  if (x && y == 0) {
    printf("No");
    return 0;
  }
  x -= y;
  if (x < 0) {
    printf("No");
    return 0;
  }
  if (x & 1)
    printf("No");
  else
    printf("Yes");
  return 0;
}
