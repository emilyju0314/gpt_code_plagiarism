#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= 1005;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1005;
    a = a * a % 1005;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int tc = nxt();
  for (int cNo = 1; cNo <= tc; cNo++) {
    int n = nxt(), a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int aa = nxt();
      if (aa % 2 != i % 2) {
        if (aa % 2 == 0)
          b++;
        else
          a++;
      }
    }
    if (b != a)
      printf("-1\n");
    else
      printf("%d\n", a);
  }
  return 0;
}
