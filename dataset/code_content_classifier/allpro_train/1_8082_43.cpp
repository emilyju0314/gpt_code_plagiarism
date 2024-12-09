#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int n = sqrt((long long)a * b * c);
  printf("%d", 4 * (n / a + n / b + n / c));
}
