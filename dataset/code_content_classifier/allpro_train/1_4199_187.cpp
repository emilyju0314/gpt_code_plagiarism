#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, count = 0;
  scanf("%I64d %I64d", &a, &b);
  while (1) {
    count += a / b;
    c = a % b;
    if (a % b == 0) {
      break;
    }
    a = b;
    b = c;
    if (b == 1) {
      count += a;
      break;
    }
  }
  printf("%I64d", count);
  return 0;
}
