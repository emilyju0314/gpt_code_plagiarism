#include <bits/stdc++.h>
using namespace std;
bool islucky(int x) {
  if (x < 0) x = -x;
  int rem = x % 10;
  while (x) {
    if (rem == 8) return true;
    x = x / 10;
    rem = x % 10;
  }
  return false;
}
int main() {
  int a, b = 1;
  scanf("%d", &a);
  a++;
  while (!islucky(a)) {
    a++;
    b++;
  }
  printf("%d\n", b);
  return 0;
}
