#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005, MaxC = 0x3F3F3F3F, NA = -1;
pair<int, int> solve(int a, int b) {
  pair<int, int> res;
  res.first = res.second = 0;
  if (a < 0) return res;
  res = solve(a - 1, b & ((1 << (a << 1)) - 1));
  switch (b >> (a << 1)) {
    case 0:
      swap(res.first, res.second);
      break;
    case 1:
      res.first += (1 << a);
      break;
    case 2:
      res.first += (1 << a);
      res.second += (1 << a);
      break;
    case 3:
      swap(res.first, res.second);
      res.second += (1 << a);
      res.first ^= (1 << a) - 1;
      res.second ^= (1 << a) - 1;
      break;
    default:
      assert(false);
      break;
  }
  return res;
}
int main(void) {
  int a, b;
  while (scanf(" %d %d", &a, &b) != EOF) {
    pair<int, int> k = solve(a, b);
    printf("%d %d\n", k.first, k.second);
  }
  return 0;
}
