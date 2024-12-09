#include <bits/stdc++.h>
using namespace std;
typedef const int& ci;
__inline__ __attribute__((always_inline)) void test() {
  int n;
  long long ans = 1;
  scanf("%d", &n);
  for (int i = n * 2; i > 2; --i) ans = ans * i % 1000000007;
  printf("%lld\n", ans);
}
int main() {
  int t;
  for (scanf("%d", &t); t; test(), --t)
    ;
  return 0;
}
