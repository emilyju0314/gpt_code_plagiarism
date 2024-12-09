#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%s\n", gcd(x, y) != 1 ? "Infinite" : "Finite");
  }
}
