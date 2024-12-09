#include <bits/stdc++.h>
using namespace std;
int n, x, i;
long long a, b;
int main() {
  scanf("%d", &n);
  while (i < n) scanf("%d", &x), a += (x + i % 2) / 2, b += (x + ++i % 2) / 2;
  printf("%lld", min(a, b));
}
