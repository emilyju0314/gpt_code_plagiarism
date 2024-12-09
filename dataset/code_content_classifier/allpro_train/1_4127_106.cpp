#include <bits/stdc++.h>
using namespace std;
int gcd[1005];
int get(int a, int b) {
  while (b) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
int main() {
  int n, now;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &gcd[i]);
    }
    now = gcd[0];
    for (int i = 1; i < n; i++) {
      now = get(gcd[i], now);
    }
    if (now == gcd[0]) {
      printf("%d\n%d", n * 2 - 1, gcd[0]);
      for (int i = 1; i < n; i++) {
        printf(" %d %d", gcd[0], gcd[i]);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
