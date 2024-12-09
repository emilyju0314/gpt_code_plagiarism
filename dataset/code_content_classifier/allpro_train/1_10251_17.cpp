#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  while (cin >> n) {
    int flag = 0;
    long long int i;
    for (int sx = 1; sx < 100; sx++) {
      long long int x = (sqrt(sx * sx + 4 * n) - sx) / 2;
      if (x * x + sx * x == n) {
        int tem = x;
        int t = 0;
        while (tem > 0) {
          t = t + tem % 10;
          tem = tem / 10;
        }
        if (sx == t) {
          flag = 1;
          printf("%d\n", x);
          break;
        }
      }
    }
    if (!flag) printf("-1\n");
  }
  return 0;
}
