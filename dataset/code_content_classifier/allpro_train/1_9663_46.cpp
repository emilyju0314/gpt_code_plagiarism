#include <bits/stdc++.h>
using namespace std;
int h1, h2;
int a, b;
int ans = 0;
int main() {
  scanf("%d%d", &h1, &h2);
  scanf("%d%d", &a, &b);
  h1 += a * 8;
  if (h1 >= h2)
    printf("0\n");
  else if (h1 < h2 && b >= a)
    printf("-1\n");
  else if (h1 < h2 && b < a) {
    int num1 = (h2 - h1) % ((a - b) * 12);
    if (num1 == 0)
      printf("%d\n", (h2 - h1) / ((a - b) * 12));
    else
      printf("%d\n", (h2 - h1) / ((a - b) * 12) + 1);
  }
  return 0;
}
