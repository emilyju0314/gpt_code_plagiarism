#include <bits/stdc++.h>
int max(int a, int b) { return a > b ? a : b; }
int cal(int p, int t) { return max(3 * p / 10, p - p / 250 * t); }
int main() {
  int i, j;
  int a, b, c, d;
  while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
    int ans1 = cal(a, c), ans2 = cal(b, d);
    if (ans1 == ans2)
      printf("Tie\n");
    else if (ans1 > ans2)
      printf("Misha\n");
    else
      printf("Vasya\n");
  }
  return 0;
}
