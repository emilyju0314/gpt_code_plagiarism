#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b)
    return gcd(b, a % b);
  else
    return a;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int x = gcd(a, b);
  a /= x;
  b /= x;
  if (abs(a - b) == 1) return puts("Equal");
  if (a < b)
    puts("Dasha");
  else
    puts("Masha");
}
